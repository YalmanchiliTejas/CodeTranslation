#include<bits/stdc++.h>

using namespace std;

string s;
int main()
{
  cin>>s;
  int ok=0;
  for(int i=1;i<3;i++) if(s[i]!=s[0]) ok=1;
  if(ok) cout<<"Yes";
  else cout<<"No";
}