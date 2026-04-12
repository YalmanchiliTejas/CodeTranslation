#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(a) ((a) & -(a))
#define clean(a, b) memset(a, b, sizeof(a))
#define eps (-1e8)
#define make_pair P
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 3e5 + 9;

int _;


ll a[maxn],sum[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
	}
	ll ans=0;
	for(int i=n;i>=1;i--)
	{
		sum[i]=(sum[i+1]+a[i])%mod;
	}
	for(int i=n-1;i>=1;i--)
	{
		ans=(a[i]*sum[i+1]%mod+ans)%mod;
	}
	printf("%lld\n",ans);
    return 0;
}
 