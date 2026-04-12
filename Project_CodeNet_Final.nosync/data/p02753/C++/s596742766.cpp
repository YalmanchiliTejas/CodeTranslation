#include<bits/stdc++.h>
using namespace std;
int main()
{
  int cA=0,cB=0;
string s;
  cin>>s;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]=='A')
      cA++;
    else
      cB++;
  }
  if(cA>0 && cB>0)
    cout<<"Yes";
  else
    cout<<"No";
}