#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int Mod=1e9+7;
int n;
int a[200010];
ll sum[200010];
ll ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=(sum[i-1]+a[i])%Mod;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+(ll)a[i]*((sum[n]-sum[i])%Mod+Mod)%Mod)%Mod;
    }
    printf("%lld",ans);
    return 0;
}