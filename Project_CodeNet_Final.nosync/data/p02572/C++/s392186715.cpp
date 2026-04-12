#include <iostream>
#include <cstdio>
using namespace std;
const int INF=2e5+5;
const int Mod=1e9+7;
long long sum[INF],n,a[INF],ans;
signed main()
{
        scanf("%lld",&n);
        for (int i=1; i<=n; i++) scanf("%lld",&a[i]);
        for (int i=n; i>=1; i--) sum[i]=(sum[i+1]+a[i])%Mod;
        for (int i=1; i<=n; i++) ans+=(a[i]*sum[i+1])%Mod,ans%=Mod;
        cout<<ans<<"\n";
        return 0;
}
