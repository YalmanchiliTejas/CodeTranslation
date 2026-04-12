#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	const int N =  3005;

	int n, mod, C[N][N], S[N][N];

	inline int qpow(int x, int tim, const int p = mod)
	{
		int ans = 1;
		for (; tim; tim >>= 1, x = (ll)x * x % p)
			if (tim & 1)
				ans = (ll)ans * x % p;
		return ans;
	}

	void work()
	{
		scanf("%d%d", &n, &mod);
		for (int i = 0; i <= n; i++)
		{
			C[i][0] = 1;
			for (int j = 1; j <= i; j++)
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
		S[0][0] = 1;
		for (int i = 1; i <= n + 1; i++)
		   	for (int j = 1; j <= i; j++)
				S[i][j] = (S[i - 1][j - 1] + (ll)S[i - 1][j] * j) % mod;
		int ans = 0;
		for (int i = 0; i <= n; i++)
		{
			int sum = 0, tmp = qpow(2, n - i), v = 1;
			for (int j = 0; j <= i; j++, v = (ll)v * tmp % mod)
				sum = (sum + (ll)S[i + 1][j + 1] * v) % mod;
			ans = (ans + (ll)((i & 1) ? mod - 1 : 1) * C[n][i] % mod * qpow(2, qpow(2, n - i, mod - 1)) % mod * sum % mod) % mod;
		}
		printf("%d\n", ans);
	}
}

int main()
{
	TYC::work();
	return 0;
}