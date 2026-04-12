#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;
  string s1;
  cin>>n>>s1>>k;
  for(int i=0;i<s1.size();i++)
    if(s1[i]!=s1[k-1])cout<<"*";
    else cout<<s1[i];
  cout<<"\n";
  return 0;
}