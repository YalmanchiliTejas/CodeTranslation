#include <cstdio>
#include <cstring>

typedef long long ll;
const int N=200005;
const int mod=1e9+7;

ll n,a[N],res;

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        res=(res+a[i]*a[i-1])%mod;
        a[i]=(a[i]+a[i-1])%mod;
    }
    printf("%d\n",res);
    return 0;
}