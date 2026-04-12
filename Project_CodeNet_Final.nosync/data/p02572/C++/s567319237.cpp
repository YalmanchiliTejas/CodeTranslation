#include <stdio.h>

typedef long long ll;

const ll MOD = (ll)1e9 + 7;

int main(void)
{
	ll n, i, tot = 0, sum = 0;

	scanf("%lld", &n);
	for (i = 1; i <= n; i++)
	{
		ll x;

		scanf("%lld", &x);

		sum = (sum + x) % MOD;
		tot = (tot + x * x) % MOD;
	}

	ll db = (sum * sum % MOD - tot + MOD) % MOD;

	if (db % 2 == 0)
		printf("%lld", db / 2);
	else
		printf("%lld", (db + MOD) / 2);
	return 0;
}