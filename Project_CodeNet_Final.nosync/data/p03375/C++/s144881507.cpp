#include <bits/stdc++.h>
using namespace std;

const int maxN = 3005;

int n, mod;
int S[maxN + 1][maxN + 1], C[maxN + 1][maxN + 1];
int pw[maxN * maxN + 1];

inline int ADD(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }

inline int SUB(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }

inline int mpow(int a, int x, int mod)
{
	int ans = 1;
	while(x)
	{
		if(x & 1) ans = 1ll * ans * a % mod;
		a = 1ll * a * a % mod;
		x >>= 1;
	}
	return ans;
}

int main()
{
	scanf("%d %d", &n, &mod);

	S[0][0] = C[0][0] = 1;
	for(int i = 1; i <= n + 1; i++)
	{
		C[i][0] = 1;
		for(int j = 1; j <= i; j++)
			C[i][j] = ADD(C[i - 1][j], C[i - 1][j - 1]),
			S[i][j] = ADD(S[i - 1][j - 1], 1ll * j * S[i - 1][j] % mod);
	}

	pw[0] = 1;
	for(int i = 1; i <= n * n; i++)
		pw[i] = 2ll * pw[i - 1] % mod;

	int ans = 0;
	for(int i = 0; i <= n; i++)
	{
		int res = 0;
		for(int j = 0; j <= i; j++)
			res = ADD(res, 1ll * pw[j * (n - i)] * S[i + 1][j + 1] % mod);
		res = 1ll * res * C[n][i] % mod * mpow(2, mpow(2, n - i, mod - 1), mod) % mod;
		ans = (i & 1) ? SUB(ans, res) : ADD(ans, res);
	}

	printf("%d", ans);
	return 0;
}
