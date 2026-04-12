#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f first
#define s second
#define pb push_back
#define mod 1000000007
ll dp[2][10001][101];
void solve()
{
    ll d;
    string k;
    cin>>k>>d;
    ll n=k.length();
    memset(dp,0,sizeof(dp));
    dp[1][0][0]=1ll;
    for(ll x=1;x<=n;x++)
    {
     ll g=k[x-1]-'0';
     for(ll z=0;z<10;z++)
     {
        for(ll y=0;y<d;y++)
        {
            if(z<g)
            {
              dp[0][x][y]+=(dp[1][x-1][(10*d+y-z)%d]+dp[0][x-1][(10*d+y-z)%d]);
              dp[0][x][y]%=mod;
            }
            if(z==g)
            {
              dp[1][x][y]+=(dp[1][x-1][(10*d+y-z)%d]);
              dp[0][x][y]+=(dp[0][x-1][(10*d+y-z)%d]);
              dp[1][x][y]%=mod;
              dp[0][x][y]%=mod;
            }
            if(z>g)
            {
                  dp[0][x][y]+=(dp[0][x-1][(10*d+y-z)%d]);
                  dp[0][x][y]%=mod;
            }
        }
     }
    }
    cout<<(mod+dp[0][n][0]+dp[1][n][0]-1)%mod;
}
int main()
{ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll i=1;
  //cin>>i;
  ll k=0;
  while(k<i)
  {
       solve();
       ++k;
  }   
}
    