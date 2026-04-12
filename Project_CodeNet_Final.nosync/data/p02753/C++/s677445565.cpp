#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define vpll vector <pll>
#define pb push_back

int main()
{
    int i=0;
  string s;
  cin>>s;
  if((s[i]=='A' && s[i+1]=='A' && s[i+2]=='A') || (s[i]=='B' && s[i+1]=='B' && s[i+2]=='B'))
    cout<<"No";
  else cout<<"Yes";
  return 0;
}
