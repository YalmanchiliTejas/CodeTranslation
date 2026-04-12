#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	char ch; bool flag = false; res = 0;
	while (ch = getchar(), !isdigit(ch) && ch != '-');
	ch == '-' ? flag = true : res = ch ^ 48;
	while (ch = getchar(), isdigit(ch))
		res = res * 10 + ch - 48;
	flag ? res = -res : 0;
}

const int N = 1e7 + 5;
const int mod = 998244353;
int fra[N], inv[N], ex[N], n;

inline int quick_pow(int x, int k)
{
	int res = 1;
	while (k)
	{
		if (k & 1)
			res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		k >>= 1;
	}
	return res;
}

inline void add(int &x, int y)
{
	x += y;
	x >= mod ? x -= mod : 0;
}

inline void dec(int &x, int y)
{
	x -= y;
	x < 0 ? x += mod : 0;
}

inline int C(int n, int m)
{
	return 1ll * fra[n] * inv[m] % mod * inv[n - m] % mod;
}

int main()
{
	read(n);
	fra[0] = 1;
	for (int i = 1; i <= n; ++i)
		fra[i] = 1ll * fra[i - 1] * i % mod;
	inv[n] = quick_pow(fra[n], mod - 2);
	for (int i = n; i >= 1; --i)
		inv[i - 1] = 1ll * inv[i] * i % mod;
	ex[0] = 1;
	for (int i = 1; i <= n; ++i)
		add(ex[i] = ex[i - 1], ex[i - 1]);

	int half = n >> 1, ans = quick_pow(3, n);
	for (int i = half + 1; i <= n; ++i)
		dec(ans, 2ll * C(n, i) * ex[n - i] % mod);
	printf("%d\n", ans);
}