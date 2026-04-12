/*
СТРОИМ СТЕНУ РАБОТЯГИ!
█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█
█═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═█
█═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═█
█═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═█
█═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═█
█═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═█
█═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═█
█═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═█
█═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═█
█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 1007;
ll cnk[MAXN][MAXN];
ll dp[MAXN][MAXN];
ll binaryPow(ll x, ll y, ll MOD)
{
	if (y == 0) return 1;
	if (y % 2 == 0)
	{
		ll tmp = binaryPow(x, y / 2, MOD);
		return (tmp * tmp) % MOD;
	}
	else
	{
		return binaryPow(x, y - 1, MOD) * x % MOD;
	}
}
ll moduloInverse(ll x, ll MOD)
{
	return binaryPow(x, MOD - 2, MOD);
}
ll facts[1007];
ll rfacts[1007];
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	cnk[0][0] = 1;
	facts[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		facts[i] = (facts[i - 1] * i) % MOD;
		cnk[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % MOD;
		}
	}
	rfacts[n] = moduloInverse(facts[n], MOD);
	for (int i = n - 1; i >= 0; i--)
	{
		rfacts[i] = (rfacts[i + 1] * (i + 1)) % MOD;
	}
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	for (int i = a - 1; i <= b; i++)
	{
		dp[0][i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = a; j <= b; j++)
		{
			dp[i][j] = dp[i][j - 1];
			ll ways = 1;
			if (i == 3 && j == 3)
			{
				int x = 228;
			}
			for (int take = 1; take <= d && j * take <= i; take++)
			{
				ways = (ways * cnk[i - j * (take - 1)][j]) % MOD;
				if (take >= c)
				{
					dp[i][j] = (dp[i][j] + dp[i - j * take][j - 1] * ways % MOD * rfacts[take]) % MOD;
				}
			}
		}
	}
	printf("%lld\n", dp[n][b]);
}

