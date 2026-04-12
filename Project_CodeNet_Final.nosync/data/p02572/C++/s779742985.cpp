#pragma warning(disable:4996)
#include <stdio.h>
typedef long long ll;
ll MOD = 1000000007;
ll sum[200200];
ll a[200200];
int main()
{
	ll n;
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
		sum[i] %= MOD;
	}
	ll ans=0;
	for (ll i = n; i >= 1; i--)
	{
		ans += (a[i] * (sum[i-1]))%MOD;
		ans %= MOD;
	}
	printf("%lld", ans);
}