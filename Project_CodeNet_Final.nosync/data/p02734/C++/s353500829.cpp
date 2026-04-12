#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const long long mod=998244353;
int n,s;
long long a[3005],dp[3005];
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    memset(dp,0,sizeof(dp));
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        dp[0]++;
        for(int j=s;j>=a[i];j--)
            dp[j]=(dp[j]+dp[j-a[i]])%mod;
        ans=(ans+dp[s])%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
