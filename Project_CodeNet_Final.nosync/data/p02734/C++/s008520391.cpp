//Catchharsh
#include<bits/stdc++.h>
#define ll long long int 
#define ld long double
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define F first
#define S second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl '\n'
#define see(x) cout<<#x<<" = "<<x<<endl
const ll MOD = 998244353;
const ll INF = 1011111111;
const ll LLINF = 1000111000111000111LL;
const ld EPS = 1e-10;
const ld PI = 3.14159265358979323;
using namespace std;
ll power (ll base,ll exponent)
{
    ll ans=1;
    //base%=MOD;
    //exponent%=(MOD-1);
    while(exponent!=0)
    {
      if(exponent&1) ans=(1LL*ans*base);
      base=(1LL*base*base);
      exponent>>=1;
    }
    return ans;
}
ll n,sum;
ll ar[3005];
ll dp[3005][3005];
ll solve(ll idx,ll ss)
{
  if(idx>=n)
  {
     return 0; 
  }
  if(dp[idx][ss]!=-1) return dp[idx][ss];
  ll ans=0;
  if(ar[idx]==ss)
  {
     ans=(n-idx+solve(idx+1,ss))%MOD;
  }
  else if(ar[idx]<ss)
  {
     ans=(solve(idx+1,ss)+solve(idx+1,ss-ar[idx]))%MOD;
  }
  else
  {
    ans=solve(idx+1,ss)%MOD;
  }
  return dp[idx][ss]=ans%MOD;
}
int32_t main()
{   
     IOS;
     cin>>n>>sum;
     memset(dp,-1,sizeof dp)
;     for(ll i=0;i<n;i++) cin>>ar[i];
      ll f=0;
    for(ll i=0;i<n;i++)
    {
      f+=solve(i,sum);
      f%=MOD;
    }
    cout<<f<<endl;
     
     
     
     cerr <<endl<< "Time elapsed : " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';             
}