#include <bits/stdc++.h>

typedef long long LL;
typedef unsigned long long ULL;
const int N = 16384, mod = 998244353;

int pow(int x, int y, int ans = 1) {
	for (; y; y >>= 1, x = (LL) x * x % mod)
		if (y & 1) ans = (LL) ans * x % mod;
	return ans;
}
int n, m, dp[2][N], ans, c = 1, e[N], factor[N], ifactor[N];

int w[N], wn[N], lim, s, rev[N];
void fftinit(int len) {
	wn[0] = lim = 1, s = -1; while (lim < len) lim <<= 1, ++s;
	for (int i = 0; i < lim; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << s;
	const int g = pow(3, (mod - 1) / lim);
	for (int i = 1; i < lim; ++i) wn[i] = (LL) wn[i - 1] * g % mod;
}
void fft(int *A, int typ) {
	static ULL tmp[N];
	for (int i = 0; i < lim; ++i) tmp[rev[i]] = A[i];
	for (int i = 1; i < lim; i <<= 1) {
		for (int j = 0, t = lim / i / 2; j < i; ++j) w[j] = wn[j * t];
		for (int j = 0; j < lim; j += i << 1)
			for (int k = 0; k < i; ++k) {
				const ULL x = tmp[k + j + i] * w[k] % mod;
				tmp[k + j + i] = tmp[k + j] + mod - x, tmp[k + j] += x;
			}
	}
	for (int i = 0; i < lim; ++i) A[i] = tmp[i] % mod;
	if (!typ) {
		const int il = pow(lim, mod - 2); std::reverse(A + 1, A + lim);
		for (int i = 0; i < lim; ++i) A[i] = (LL) A[i] * il % mod;
	}
}

void init(int n) {
	factor[0] = 1;
	for (int i = 1; i <= n; ++i) factor[i] = (LL) factor[i - 1] * i % mod;
	ifactor[n] = pow(factor[n], mod - 2);
	for (int i = n; i; --i) ifactor[i - 1] = (LL) ifactor[i] * i % mod;
	n -= 2, fftinit(n + n + 1), std::memcpy(e + 1, ifactor + 3, n << 2), fft(e, 1);
}
int c2(int n) { return (LL) n * (n - 1) / 2 % mod; }
void transform(int *a, int *b) {
	static int c[N];
	std::memcpy(c, a, n + 1 << 2);
	for (int i = 0; i <= n; ++i)
		a[i] = (LL) a[i] * ifactor[i] % mod;
	fft(a, 1);
	for (int i = 0; i < lim; ++i)
		b[i] = (LL) a[i] * e[i] % mod;
	fft(b, 0);
	for (int i = 0; i <= n; ++i)
		b[i] = ((LL) b[i] * factor[i + 2] + (LL) c[i] * (c2(i + 1) + 1)) % mod;
	std::memset(b + n + 1, 0, lim - n - 1 << 2);
}

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n >> m, dp[0][0] = 1, init(n + 2);
	for (int i = 1; i <= m; ++i) transform(dp[i & 1 ^ 1], dp[i & 1]);
	for (int i = 0; i <= n; ++i) {
		ans = (ans + (LL) c * dp[m & 1][i]) % mod;
		c = (LL) pow(i + 1, mod - 2, n - i) * c % mod;
	}
	std::cout << ans << '\n';
	return 0;
}