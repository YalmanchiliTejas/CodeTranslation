#include <cstdio>
#include <algorithm>
using namespace std;
#define N 10000000 + 5
#define Mod 998244353

int n, ans, Fac[N], Inv[N], Pow3[N], Pow2[N];

void Prepare()
{
	Fac[0] = Inv[0] = Inv[1] = Pow3[0] = Pow2[0] = 1;
	for (int i = 1; i <= n; i ++)
	{
		Fac[i] = 1LL * Fac[i - 1] * i % Mod;
		Pow3[i] = 3LL * Pow3[i - 1] % Mod;
		Pow2[i] = 2LL * Pow2[i - 1] % Mod;
	}
	for (int i = 2; i <= n; i ++)
		Inv[i] = Mod - (1LL * Inv[Mod % i] * (Mod / i) % Mod);
	for (int i = 2; i <= n; i ++)
		Inv[i] = 1LL * Inv[i - 1] * Inv[i] % Mod;
}

inline int C(int u, int v)
{
	if (u < 0 || v < 0 || u < v)
		return 0;
	return 1LL * Fac[u] * Inv[v] % Mod * Inv[u - v] % Mod;
}

inline int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

int Calc()
{
	int res = 0;
	for (int t = n / 2 + 1; t <= n; t ++)
		res = (2LL * C(n, t) * Pow2[n - t] + res) % Mod;
	return res;
}

int main()
{
	scanf("%d", &n);
	Prepare();
	ans = Inc(Pow3[n], Mod - Calc());
	printf("%d\n", ans);
	return 0;
}