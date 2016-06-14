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
    if(pinyin.at(i)!='n')  //不是n从该辅音前分开
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
    else                 //是n,继续向后
    {
     if(i==pinyin.size()-1)
     {
      cout<<pinyin.at(i);
      continue;
     }
     else
      i++;   //继续向后
     if(pinyin.at(i)=='a' || pinyin.at(i)=='e' || pinyin.at(i)=='i' || pinyin.at(i)=='o' || pinyin.at(i)=='u' || pinyin.at(i)=='v')   //如果是原音,从n前分开
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
     //如果是辅音字母
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
        i++;  //继续向后
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
      else   //不是g的辅音字母,从n后分开
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
