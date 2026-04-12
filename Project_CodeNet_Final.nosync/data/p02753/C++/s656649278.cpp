#include <bits/stdc++.h>
using namespace std;
int main()
{
string s;
  cin>>s;
  int na=0,nb=0;
  (s[0]=='A')?na++:nb++;
  (s[1]=='A')?na++:nb++;
  (s[2]=='A')?na++:nb++;
  if(na>0&&nb>0)cout<<"Yes";
  else cout<<"No";
  return 0;
}