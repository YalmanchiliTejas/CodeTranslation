#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int i,a=0,b=0;
  for(i=0;i<s.size();++i)
  {
    if(s[i]=='A')
      a++;
    else
      b++;
  }
  if(a>0 and b>0)
    cout<<"Yes";
  else
    cout<<"No";
}