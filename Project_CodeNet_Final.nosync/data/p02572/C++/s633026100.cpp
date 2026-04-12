#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
const ll mod=1e9+7;
const ll inv=(mod+1)/2;
int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0,extra=0;
    for(int i=1;i<=n;i++)
    {
        ll a;
        scanf("%lld",&a);
        sum=(sum+a)%mod;
        extra=(extra+a*a%mod)%mod;
    }
    ll ans=(sum*sum%mod-extra+mod)%mod*inv%mod;
    printf("%lld\n",ans);
    return 0;
}
