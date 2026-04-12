#include<bits/stdc++.h>

using namespace std;
inline void y()
{
  cout<<"YES\n";
}
inline void n()
{
  cout<<"NO\n";
}
int a,b,c;
string s;
int main()
{
  cin>>a>>b>>c;
  if((b*10+c)%4==0)y();
  else n();
  return 0;
}

