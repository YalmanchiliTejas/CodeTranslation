#include <stdio.h>

#define ll long long

const ll mod = 1e9 + 7;

ll fact[200005] = { 1, };
ll fact_inv[200005] = { 1, };

ll get_inv(ll num)
{
	ll pow = mod - 2;
	ll ret = 1;
	ll mul = num;

	while (pow)
	{
		if (pow & 1) ret = (ret*mul) % mod;
		mul = (mul*mul) % mod;
		pow /= 2;
	}

	return ret;
}

int main()
{
	for (int i = 1; i <= 200000; ++i) fact[i] = (fact[i - 1] * i) % mod;
	fact_inv[200000] = get_inv(fact[200000]);
	for (int i = 199999; i >= 1; --i) fact_inv[i] = (fact_inv[i + 1] * (i + 1))%mod;

	ll N, M, K;

	scanf("%lld %lld %lld", &N, &M, &K);

	ll ans = 0LL;

	for (ll i = 1; i < N; ++i)
	{
			ll temp = (i*((M*M) % mod)) % mod;
			ll mul = (((fact[N*M - 2] * fact_inv[K - 2]) % mod)*fact_inv[N*M - K]) % mod;
			temp = (temp*mul) % mod;
			temp = (temp*(N - i)) % mod;
			ans = (ans + temp) % mod;
	}

	for (ll i = 1; i < M; ++i)
	{
		ll temp = (i*((N*N) % mod)) % mod;
		ll mul = (((fact[N*M - 2] * fact_inv[K - 2]) % mod)*fact_inv[N*M - K]) % mod;
		temp = (temp*mul) % mod;
		temp = (temp*(M - i)) % mod;
		ans = (ans + temp) % mod;
	}

	printf("%lld\n", ans);

	return 0;
}