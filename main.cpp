#include <iostream>
#include <string>
using namespace std;
int main()
{
  cout<<"enter:"<<endl;
  string pinyin;
  cin >> pinyin;
  int i = 0;
  for(i=0;i<pinyin.size();i++)
  {
   if(pinyin.at(i)=='a' || pinyin.at(i)=='e' || pinyin.at(i)=='i' || pinyin.at(i)=='o' || pinyin.at(i)=='u' || pinyin.at(i)=='v')
   {
    cout<<pinyin.at(i);
    continue;
   }
   else
   {
    if(pinyin.at(i)!='n')  //����n�Ӹø���ǰ�ֿ�
    {
     if(i==0)
     {
      cout<<pinyin.at(i);
      if((pinyin.at(i)=='z'|pinyin.at(i)=='c'|pinyin.at(i)=='s')&&(pinyin.at(i+1)=='h'))
      {
       cout<<'h';
          i++;
      }
      continue;
     }
     else
     {
      cout<<' '<<pinyin.at(i);
      if((pinyin.at(i)=='z'|pinyin.at(i)=='c'|pinyin.at(i)=='s')&&(pinyin.at(i+1)=='h'))
       {
        cout<<'h';
        i++;
       }
      continue;
     }
    }
    else                 //��n,�������
    {
     if(i==pinyin.size()-1)
     {
      cout<<pinyin.at(i);
      continue;
     }
     else
      i++;   //�������
     if(pinyin.at(i)=='a' || pinyin.at(i)=='e' || pinyin.at(i)=='i' || pinyin.at(i)=='o' || pinyin.at(i)=='u' || pinyin.at(i)=='v')   //�����ԭ��,��nǰ�ֿ�
     {
      if(i==1)
      {
       cout<<'n'<<pinyin.at(i);
       continue;
      }
      else
      {
       cout<<' '<<'n'<<pinyin.at(i);
       continue;
      }
     }
     //����Ǹ�����ĸ
     else
     {
      if(pinyin.at(i)=='g')
      {
       if(i==pinyin.size()-1)
       {
        cout<<'n'<<pinyin.at(i);
        continue;
       }
       else
        i++;  //�������
       if(pinyin.at(i)=='a' || pinyin.at(i)=='e' || pinyin.at(i)=='i' || pinyin.at(i)=='o' || pinyin.at(i)=='u' || pinyin.at(i)=='v')
       {
        cout<<'n'<<' '<<'g'<<pinyin.at(i);
        continue;
       }
       else
       {
        cout<<'n'<<'g'<<' '<<pinyin.at(i);
        continue;
       }
      }
      else   //����g�ĸ�����ĸ,��n��ֿ�
      {
       cout<<'n'<<' '<<pinyin.at(i);
       continue;
      }
     }
    }
   }
  }
  cout<<endl;
  return 0;
}
