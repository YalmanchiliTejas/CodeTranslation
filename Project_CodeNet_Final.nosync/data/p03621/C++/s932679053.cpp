#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 32770;
const int MAXM = 20;
const int mod = 998244353;
const int G = 3;

namespace FFT
{
	int wn[MAXM], R[MAXN], L, n;

	inline int Qow(int x, int y)
	{
		int ret = 1;
		for (; y; y >>= 1, x = 1LL * x * x % mod)
			if (y & 1)
				ret = 1LL * ret * x % mod;
		return ret;
	}

	inline int Inv(int x)
	{
		return Qow(x, mod - 2);
	}

	inline void Ini(int len)
	{
		for (n = 1, L = 0; n < len; n <<= 1, L ++);
		for (int i = 1; i < n; i ++)
			R[i] = (R[i >> 1] >> 1) | ((i & 1) << L - 1);
		wn[0] = Qow(G, mod - 1 >> L);
		for (int i = 1; i < L; i ++)
			wn[i] = 1LL * wn[i - 1] * wn[i - 1] % mod;
	}

	inline void Ini_Inv()
	{
		wn[0] = Inv(wn[0]);
		for (int i = 1; i < L; i ++)
			wn[i] = 1LL * wn[i - 1] * wn[i - 1] % mod;
	}

	inline void FFT(int *x)
	{
		for (int i = 0; i < n; i ++)
			if (i < R[i])
				swap(x[i], x[R[i]]);
		for (int i = 1, l = L - 1; i < n; i <<= 1, l --)
			for (int j = 0; j < n; j += i << 1)
				for (int k = 0, w = 1, u, v; k < i; k ++, w = 1LL * w * wn[l] % mod)
					u = x[j + k], v = 1LL * x[i + j + k] * w % mod, x[j + k] = (u + v) % mod, x[i + j + k] = (u + mod - v) % mod;
	}

	inline void Cpy(int *x, int n, int *y, int m)
	{
		for (int i = 0; i < n; i ++)
			y[i] = x[i];
		for (int i = n; i < m; i ++)
			y[i] = 0;
	}

	inline void Mul(int *a, int n, int *b, int m, int *ret)
	{
		static int x[MAXN], y[MAXN];
		Ini(n + m - 1);
		Cpy(a, n, x, FFT::n); Cpy(b, m, y, FFT::n);
		FFT(x); FFT(y);
		for (int i = 0; i < FFT::n; i ++)
			x[i] = 1LL * x[i] * y[i] % mod;
		Ini_Inv();
		FFT(x);
		int v = Inv(FFT::n);
		for (int i = 0; i < FFT::n; i ++)
			ret[i] = 1LL * v * x[i] % mod;
	}
}

int n, m, fac[MAXN], inv[MAXN], x[MAXN], r[MAXN];
char s[MAXN], t[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	scanf("%s%s", s + 1, t + 1);
	for (int i = 1, l = strlen(s + 1); i <= l; i ++)
		if (s[i] == '1' && t[i] == '1')
			n ++;
		else if (s[i] == '1' && t[i] == '0')
			m ++;
	r[0] = fac[0] = inv[0] = fac[1] = inv[1] = 1;
	for (int i = 2; i <= n + m + 1; i ++)
		fac[i] = 1LL * fac[i - 1] * i % mod, inv[i] = 1LL * (mod - mod / i)  * inv[mod % i] % mod;
	for (int i = 2; i <= n + m + 1; i ++)
		inv[i] = 1LL * inv[i] * inv[i - 1] % mod;
	for (int i = 0; i <= n; i ++)
		x[i] = inv[i + 1];
	for (int t = m; t; t >>= 1, FFT::Mul(x, n + 1, x, n + 1, x))
		if (t & 1)
			FFT::Mul(x, n + 1, r, n + 1, r);
	int ret = 0;
	for (int i = 0; i <= n; i ++)
		ret = (ret + r[i]) % mod;
	return printf("%d\n", 1LL * ret * fac[n] % mod * fac[m] % mod * fac[n + m] % mod), 0;
}
