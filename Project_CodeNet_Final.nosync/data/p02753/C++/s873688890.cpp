#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int c1=0,c2=0;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]=='A') c1++;
    else c2++;
  }
  if(c1==s.length() || c2==s.length())
    cout<<"No";
  else cout<<"Yes";
  return 0;
}