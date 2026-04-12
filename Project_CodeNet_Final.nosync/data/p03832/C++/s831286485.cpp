#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define N (int)1e5
#define mod (int)(1e9 + 7)
typedef long long LL;
LL n, a, b, c, d, s;
LL dp[1001][1001], inv[3333], fact[1001];
int extgcd(int a, int b, int& x, int& y)
{
	int d = a;
	if (b != 0)
	{
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else
	{
		x = 1; y = 0;
	}
	return d;
}
int mod_inverse(int a, int m)
{
	int x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}
int main()
{
	cin >> n >> a >> b >> c >> d;
	fact[0] = 1;
	inv[0] = 1;
	inv[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		fact[i] = i;
		if (fact[i - 1]) {
			fact[i] *= fact[i - 1];
			fact[i] %= mod;
			inv[i] = mod_inverse(fact[i], mod);
		}
	}

	dp[a - 1][0] = 1;
	for (int i = a; i <= b; i++)
	{

		for (int k = 0; k <= n; k++)
		{
			s = 1;
			LL l = 0;
			for (int j = c; j <= d; j++)
			{

				if (i * j + k <= n)
				{
					for (l; l < j; l++)
					{
						s *= (fact[n - k - l * i] * inv[n - k - i - l * i]) % mod * inv[i] % mod;
						s %= mod;
					}
					s *= inv[j];
					s %= mod;
					dp[i][i * j + k] += (dp[i - 1][k] * s) % mod;
					dp[i][i * j + k] %= mod;
					s *= fact[j];
					s %= mod;
				}
				else
				{
					break;
				}
			}
		}
		for (int k = 0; k <= n; k++)
		{
			dp[i][k] += dp[i - 1][k];
			dp[i][k] %= mod;
		}
	}

	cout << dp[b][n] % mod << endl;
}