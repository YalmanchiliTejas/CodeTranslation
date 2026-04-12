#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 3010;

ll Pow(ll a, ll b, ll MOD)
{
	ll ans = 1;
	for(; b; b >>= 1)
	{
		if(b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
	}
	return ans;
}

int n; ll MOD;
ll C[MAXN][MAXN];
ll S[MAXN][MAXN];

ll calc(int i)
{
	ll res = 0, now = 1;
	ll P1 = Pow(2, Pow(2, n - i, MOD - 1), MOD);
	ll P2 = Pow(2, n - i, MOD);
	for(int j = 0; j <= i; ++j)
	{
		res += S[i + 1][j + 1] * now % MOD;
		res %= MOD; now = now * P2 % MOD;
	}
	res = res * P1 % MOD * C[n][i] % MOD;
	return res;
}

int main()
{
	scanf("%d %lld", &n, &MOD);
	C[0][0] = S[0][0] = 1;
	for(int i = 1; i <= n + 1; ++i)
	{
		C[i][0] = 1, S[i][0] = 0;
		for(int j = 1; j <= i; ++j)
		{
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
			S[i][j] = (S[i - 1][j - 1] + S[i - 1][j] * j % MOD) % MOD;
		}
	}
	ll ans = 0;
	for(int i = 0; i <= n; ++i)
	{
		if(i & 1) ans = (ans - calc(i)) % MOD;
		else ans = (ans + calc(i)) % MOD;
	}
	printf("%lld\n", (ans + MOD) % MOD);
	return 0;
}