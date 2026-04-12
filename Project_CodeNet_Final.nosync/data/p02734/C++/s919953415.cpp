#include<bits/stdc++.h>
using namespace std;
long long dp[3005][6005]={0};
int a[3005];
const long long MOD=998244353;
int main()
{
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[0][0]=1;
    for(int i=1;i<=s;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=i+1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(j>=a[i])dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%MOD;
            else dp[i][j]=dp[i-1][j];
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+dp[i][s])%MOD;
    cout<<ans<<'\n';
}
