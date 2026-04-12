#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int maxn=2e5+5;
int n,a[maxn];
ll ans,sum[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<n;i++){
		ans=(ans+((sum[n]-sum[i])%mod)*a[i])%mod;
	}
	printf("%lld",ans);
}