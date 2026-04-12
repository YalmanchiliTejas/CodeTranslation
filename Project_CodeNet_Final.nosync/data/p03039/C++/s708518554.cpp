#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;
ll n, m, k;

ll my_pow(ll a, ll n)
{
	if (n == 1) return a;
	if (n % 2)
	{
		ll res = my_pow(a, n - 1);
		res *= a;
		return res % MOD;
	}

	ll res = my_pow(a, n / 2);
	return res * res % MOD;
}

ll gb(ll a, ll b)
{
	ll ans = 1;
	for (int i = 1; i <= a; i++)
	{
		ans *= i;
		ans %= MOD;
	}

	for (int i = 1; i <= b; i++)
	{
		ans *= my_pow(i, MOD - 2);
		ans %= MOD;
	}

	for (int i = 1; i <= a - b; i++)
	{
		ans *= my_pow(i, MOD - 2);
		ans %= MOD;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;

	ll ans = 0;

	ll t = 0;
	for (ll i = 1; i < m; i++)
	{
		t += i * (m - i) % MOD;
		t %= MOD;
	}
	t *= n * n % MOD;
	t %= MOD;

	ans += t;

	t = 0;
	for (ll i = 1; i < n; i++)
	{
		t += i * (n - i) % MOD;
		t %= MOD;
	}
	t *= m * m % MOD;
	t %= MOD;

	ans += t;
	ans %= MOD;

	ll b = gb(n*m-2, k - 2);
	ans *= b;
	ans %= MOD;
	cout << ans;
}