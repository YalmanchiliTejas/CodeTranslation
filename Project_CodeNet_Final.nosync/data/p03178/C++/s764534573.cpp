#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
const ll MX=100000;
const ll mod=1e9+7;
const ll inf=1e18;
ll dp[MX+5][105][2];
string s;
ll sz;
ll d;
ll ok(ll p, ll r, ll f)
{
  if(p==sz)
  {
    if(!r)return 1;
    return 0;
  }
  if(~dp[p][r][f]) return dp[p][r][f];
  ll ret=0;
  if(!f)
  {
    for(ll i=0;i<=9;i++)
    {
      ret=(ret+ok(p+1,(r+i)%d,f))%mod;
    }
  }
  else
  {
    for(ll i=0;i<(s[p]-'0');i++)
    {
      ret=(ret+ok(p+1,(r+i)%d,1^f))%mod;
    }
    ret=(ret+ok(p+1,(r+s[p]-'0')%d,f))%mod;
  }
  return dp[p][r][f]=ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>s>>d;
  sz=s.size();
  memset(dp,-1,sizeof(dp));
  ll r=ok(0,0,1);
  cout<<(r-1+mod)%mod<<endl;
  return 0;
}
