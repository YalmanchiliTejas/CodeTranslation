#include <bits/stdc++.h>
#define modd 998244353
using namespace std;
typedef long long int ll;
int main()
{
    ll n,s=3000,dwe;
    cin>>n>>dwe;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    ll dp[n+1][s+1][2];
    for(ll i=0;i<=s;i++)
    {
        dp[1][i][1]=0;
        dp[1][i][0]=0;
    }
    dp[1][a[1]][0] = dp[1][a[1]][1] = 1LL;
    for(ll i=2;i<=n;i++)
    {
        for(ll j=0;j<a[i];j++)
        {
            dp[i][j][0]=0;
            dp[i][j][1]=dp[i-1][j][1];
        }
        dp[i][a[i]][0]=i;
        dp[i][a[i]][1] = (dp[i][a[i]][0] + dp[i-1][a[i]][1])%modd;
        for(ll j=a[i]+1;j<=s;j++)
        {
            dp[i][j][0] = dp[i-1][j-a[i]][1];
            dp[i][j][1] = (dp[i-1][j][1] + dp[i][j][0])%modd;
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        ans = (ans + (n-i+1LL)*dp[i][dwe][0])%modd;
    }
    cout<<ans<<"\n";
    return 0;
}
