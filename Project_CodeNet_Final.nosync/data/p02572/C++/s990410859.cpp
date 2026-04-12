#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e5+5;
ll a[M];
ll sum[M];
const ll mod=1e9+7;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
        sum[i]=(sum[i-1]+a[i])%mod;
    }
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        res=(res+a[i]*(sum[n]-sum[i]+mod)%mod)%mod;
    }
    printf("%lld\n",res);
    return 0;
}
