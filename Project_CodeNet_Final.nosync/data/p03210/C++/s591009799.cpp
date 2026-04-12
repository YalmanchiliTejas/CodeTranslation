#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll f=false;
  string s;
  cin>>s;
  if(s[0]=='7') f=true;
  if(s[0]=='5') f=true;
  if(s[0]=='3') f=true;
  if(f) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
