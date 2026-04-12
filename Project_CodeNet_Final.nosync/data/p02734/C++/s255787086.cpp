#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long ll;
int n,s,v[10001];
ll dp[10001],ans,dp1[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        int nr=v[i];
        for(int k=1;k<=s;k++)
        {
            dp1[k]=(dp[k])%mod;
            if(k-nr>=0)
                dp1[k]=(dp[k-nr]+dp1[k])%mod;
            if(k==s)
                ans=(ans+((n-i+1)*dp[k-nr])%mod)%mod;
        }
        for(int j=1;j<=s;j++)
            dp[j]=dp1[j];
        dp[nr]=(dp[nr]+i)%mod;
        if(nr==s)
            ans=(ans+(i*(n-i+1)%mod))%mod;
    }
    cout<<ans;
    return 0;
}
