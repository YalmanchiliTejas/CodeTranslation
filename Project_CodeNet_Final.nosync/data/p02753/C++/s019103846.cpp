#include<iostream>
using namespace std;
int main()
{
  string s;
  int a=0;
  int b=0;
  cin>>s;
  for(int i=0;i<3;i++)
  {
    if(s[i]=='A')
    {
      a++;
    }
    else if(s[i]='B')
    {
      b++;
    }
  }
    if(a>0&&b>0)
    {
      cout<<"Yes"<<endl;
    }
    else 
    {
      cout<<"No"<<endl;
    }
  
}