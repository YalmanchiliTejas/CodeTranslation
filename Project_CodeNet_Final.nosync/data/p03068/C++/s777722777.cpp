#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,i,k;
  cin>>n;
  string s;
  cin>>s;
  cin>>k;
  for(i=0;i<s.length();i++)
  {
    if(s[i]!=s[k-1]) s[i]='*';
  }
  cout<<s;
}