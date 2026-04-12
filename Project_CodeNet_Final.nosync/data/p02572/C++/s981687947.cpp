#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const int M=2e5+10,MOD=1E9+7;
ll sum[M],a[M];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sum[n]=0;
    for(int i=n-1;~i;i--)
        sum[i]=(sum[i+1]+a[i])%MOD;
    ll ans=0;
    for(int i=0;i<n-1;i++)
        ans=(ans+a[i]*sum[i+1]%MOD)%MOD;
    printf("%lld\n",ans);
    return 0;
}
