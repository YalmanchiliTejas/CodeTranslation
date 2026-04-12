#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sf(n) scanf("%lld",&n)
#define sff(n,m) scanf("%lld %lld",&n,&m)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PLL pair<ll,ll>
#define mod 1000000007
#define mx 100002
#define FILE freopen("input.txt","r",stdin)

ll a[mx];
ll dp[3002][3002][2];

ll F(ll st,ll en,ll t)
{
  if(st>en) return 0;
  if(dp[st][en][t]!=-1) return dp[st][en][t];

  ll ret1,ret2,ret;

  if(t){
    ret1 = a[st]+F(st+1,en,!t);
    ret2 = a[en]+F(st,en-1,!t);
    ret = max(ret1,ret2);
  }
  else{
    ret1 = F(st+1,en,!t)-a[st];
    ret2 = F(st,en-1,!t)-a[en];
    ret = min(ret1,ret2);
  }

  return dp[st][en][t] = ret;
}

int main()
{
ll n;
sf(n);

for(ll i = 1;i<=n;i++)
{
  sf(a[i]);
}

memset(dp,-1,sizeof dp);
cout<<F(1,n,1)<<endl;

return 0;
}
