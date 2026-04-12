#include<bits/stdc++.h>
using namespace std;

const int mn=2e5+7,mod=1e9+7;
long long a[mn],sum[mn],ans;
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {scanf("%lld",a+i);sum[i]=(sum[i-1]+a[i])%mod;}
    for(int i=1;i<=n;++i) ans=(ans+a[i]*(sum[n]-sum[i]+mod)%mod)%mod;
    cout<<ans;
}