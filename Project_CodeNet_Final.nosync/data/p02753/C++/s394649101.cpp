#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int a[2]={0};
  for(int i=0;i<3;i++)
  {
    a[s[i]-'A']++;
  }
  if(a[0]==3||a[1]==3)
  {
    cout<<"No\n";
  }
  else
  {
    cout<<"Yes\n";
  }
}