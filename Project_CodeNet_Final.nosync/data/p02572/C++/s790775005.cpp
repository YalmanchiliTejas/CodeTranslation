#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,a[N],sum=0,ans=0;
int main(){
	ll i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		sum=(sum+a[i])%MOD;
	}
	for(i=0;i<n;i++)
	{
		sum=(sum+MOD-a[i])%MOD;
		ans=(ans+((a[i]*sum)%MOD))%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}