#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ar[3002],s,dp[3002][3002],n,mod1=998244353;
ll rec(ll i,ll j)
{
    if(j==s)
        return n-i+2;
    if(j>s)
        return 0;
    if(i==n+1)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll z1=rec(i+1,j);
    ll z2=rec(i+1,j+ar[i]);
    dp[i][j]=(z1%mod1+z2%mod1)%mod1;
    return dp[i][j];
}
int main()
{
    ll i,ans=0;
    cin>>n>>s;
    for(i=1;i<=n;i++)
        cin>>ar[i];
    memset(dp,-1,sizeof dp);
    rec(1,0);
    for(i=1;i<=n;i++)
    {
        ans=((ans%mod1)+(dp[i][0]%mod1))%mod1;
    }
    cout<<ans;
}
