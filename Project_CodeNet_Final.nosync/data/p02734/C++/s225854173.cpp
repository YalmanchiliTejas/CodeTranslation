#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=3005;
const int mod=998244353;
int n,s,a[N],dp[N][N];

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    int res=0;
    for(int i=1;i<=n;i++)
    {
        dp[i][a[i]]=i;
        for(int j=0;j<=s;j++)
        {
            dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            if(j>=a[i]) dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
        }
        res=(res+dp[i][s]*(n-i+1))%mod;
        dp[i][s]=0;
    }
    cout<<res;
}
