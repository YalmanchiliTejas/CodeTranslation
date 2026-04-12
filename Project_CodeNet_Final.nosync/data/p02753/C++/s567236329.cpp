#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
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
      a=1;
    }
    if(s[i]=='B')
    {
      b=1;
    }
  }
  
  if(a==1&&b==1)
  {
    cout<<"Yes"<<endl;
  }
  else
  {
    cout<<"No"<<endl;
  }

  return 0;
}