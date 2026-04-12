#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> poly;
const int maxn = 8005, maxm = 205, mod = 998244353;

inline int gi()
{
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	int sum = 0;
	while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
	return sum;
}

inline int fpow(int x, int k)
{
	int res = 1;
	while (k) {
		if (k & 1) res = (ll)res * x % mod;
		k >>= 1; x = (ll)x * x % mod;
	}
	return res;
}

inline int add(int x, int y) {return x + y < mod ? x + y : x + y - mod;}
inline int sub(int x, int y) {return x < y ? x - y + mod : x - y;}

int n, m, fac[maxn], ifac[maxn];
int N, L, R[maxn << 2], w[maxn << 2];
int f[maxm][maxn];

void init(int n)
{
	for (N = 1, L = -1; N < n; N <<= 1) ++L;
	for (int i = 0; i < N; ++i) R[i] = (R[i >> 1] >> 1) | ((i & 1) << L);
	w[N >> 1] = 1;
	int wn = fpow(3, (mod - 1) / N);
	for (int i = (N >> 1) + 1; i < N; ++i) w[i] = (ll)w[i - 1] * wn % mod;
	for (int i = (N >> 1) - 1; ~i; --i) w[i] = w[i << 1];
}


void dft(poly &a)
{
	a.resize(N);
	for (int i = 0; i < N; ++i) if (i < R[i]) swap(a[i], a[R[i]]);
	for (int d = 1; d < N; d <<= 1)
		for (int i = 0; i < N; i += d << 1)
			for (int j = 0; j < d; ++j) {
				int t = (ll)w[d + j] * a[i + d + j] % mod;
				a[i + d + j] = sub(a[i + j], t);
				a[i + j] = add(a[i + j], t);
			}
}

void idft(poly &a)
{
	dft(a);
	reverse(a.begin() + 1, a.end());
	for (int i = 0, inv = fpow(N, mod - 2); i < N; ++i) a[i] = (ll)a[i] * inv % mod;
}

poly operator * (poly a, poly b)
{
	int m = a.size(), n = b.size();
	if (0 && (m < 50 || n < 50)) {
		poly c(m + n - 1);
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				c[i + j] = (c[i + j] + (ll)a[i] * b[j]) % mod;
		return c;
	}
	init(m + n - 1);
	dft(a); dft(b);
	for (int i = 0; i < N; ++i) a[i] = (ll)a[i] * b[i] % mod;
	idft(a); a.resize(m + n - 1);
	return a;
}

inline int C(int m, int n)
{
	return (ll)fac[m] * ifac[n] % mod * ifac[m - n] % mod;
}

int main()
{
	n = gi(); m = gi();
	fac[0] = 1;
	for (int i = 1; i <= n + 3; ++i) fac[i] = (ll)fac[i - 1] * i % mod;
	ifac[n + 3] = fpow(fac[n + 3], mod - 2);
	for (int i = n + 2; ~i; --i) ifac[i] = (ll)ifac[i + 1] * (i + 1) % mod;
	
	f[0][0] = 1;

	for (int j = 1; j <= m; ++j) {
		for (int i = 0; i <= n; ++i)
			f[j][i] = (1 + i + (ll)i * (i - 1) / 2 % mod) * f[j - 1][i] % mod;
		poly a(n + 3), b(n + 3);
		for (int i = 0; i <= n; ++i) a[i] = (ll)f[j - 1][i] * ifac[i] % mod;
		for (int i = 1; i <= n; ++i) b[i] = ifac[i + 2];
		a = a * b;
		for (int i = 1; i <= n; ++i) f[j][i] = (f[j][i] + (ll)a[i] * fac[i + 2]) % mod;
	}

	int ans = 0;
	for (int i = 0; i <= n; ++i) ans = (ans + (ll)f[m][i] * C(n, i)) % mod;
	printf("%d\n", ans);
	
	return 0;
}
