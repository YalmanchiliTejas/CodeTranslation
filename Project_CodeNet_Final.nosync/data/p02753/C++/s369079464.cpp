#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int i;
  for(i=1;i<s.length();i++)
  {
    if(s[i]!=s[i-1])
    {
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}