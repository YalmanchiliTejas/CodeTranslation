#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
ll dp[N],sum[N],a[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(i==1)
            sum[i]=a[i];
        else
            sum[i]=sum[i-2]+a[i];
    }
    for(int i=2;i<=n;i++)
    {
        if(i&1)
            dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        else
            dp[i]=max(dp[i-2]+a[i],sum[i-1]);
    }
    printf("%lld\n",dp[n]);
    return 0;
}