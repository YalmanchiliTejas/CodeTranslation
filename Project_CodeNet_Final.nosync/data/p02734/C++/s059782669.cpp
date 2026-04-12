#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;
int n,s,a[3005];
ll dp[3005][3005],ans;

int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++)
    {
        dp[i][0]+=i;
        dp[i][a[i]]++;
        for(int j=1;j<=s;j++)
        {
            dp[i][j]+=dp[i-1][j];
            if(j>=a[i]) dp[i][j]+=dp[i-1][j-a[i]];
            dp[i][j]%=mod;
        }
        ans=(ans+dp[i][s])%mod;
    }
    printf("%lld",ans);
    return 0;
}