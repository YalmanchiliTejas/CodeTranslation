#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int a=0,b=0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='A')
      a+=1;
    else
      b+=1;
  }
  if(a==3||b==3)
    cout<<"No";
  else
    cout<<"Yes";
return 0;
}