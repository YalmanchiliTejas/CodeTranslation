/*
Hanit Banga
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 5, mod = 1e9 + 7;

ll dp[N][N] = {0}, fact[N], factPow[N][N];

ll fastModExp(ll x, ll e);

int main()
{
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;	

	for (int j = 0; j <= n; ++j)
		dp[0][j] = 1;

	fact[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		fact[i] = (i * fact[i-1]) % mod;
		factPow[i][0] = 1;

		for (int j = 1; j <= n; ++j)
			factPow[i][j] = (fact[i] * factPow[i][j-1]) % mod;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = a; j <= b; ++j)
		{
			dp[i][j] = dp[i][j-1];
			for (int k = c; k <= d; ++k)
			{
				if (k*j > i)
					break;

				ll num = fact[i];
				ll den = fact[i - k*j];
				den = (den * factPow[j][k]) % mod;
				den = (den * fact[k]) % mod;
				den = fastModExp(den, mod - 2);
				num = (num * den) % mod;

				dp[i][j] = (dp[i][j] + num*dp[i - k*j][j-1]) % mod;
			}
		}
	}

	cout << dp[n][b];
}

ll fastModExp(ll x, ll e)
{
	ll res = 1;
	x %= mod;
	while (e)
	{
		if (e % 2)
			res = (res * x) % mod;

		e /= 2;
		x = (x * x) % mod;
	}

	return res;
}