#define FILEIO(a) freopen(a".in", "r", stdin); freopen(a".out", "w", stdout);
#include <cstdio>
#include <algorithm>

typedef long long ll;

const int N = 8005;
const int S = 1 << 17;
const int cIz = 998244353, g_cIz = 3;

inline int Pow(int a, int b) {
	int ans = 1;
	for (; b; b >>= 1) {
		if (b & 1) ans = (ll)ans * a % cIz;
		a = (ll)a * a % cIz;
	}
	return ans;
}
inline int Inv(int a) {
	return Pow(a, cIz - 2);
}

inline int getL(int n) {
	int L = 1;
	while (L < n) L <<= 1;
	return L;
}

int rev[S];
inline void init_rev(int n) {
	rev[0] = 0;
	for (int i = 1; i < n; ++i) {
		rev[i] = rev[i >> 1] >> 1 | ((i & 1) * n) >> 1;
	}
}

void NTT(int *f, int n, bool flag) {
	for (int i = 0; i < n; ++i) {
		if (i < rev[i]) std::swap(f[i], f[rev[i]]);
	}
	const int g = flag ? Inv(g_cIz) : g_cIz;
	for (int i = 1; i < n; i <<= 1) {
		const int e = Pow(g, (cIz - 1) / (i << 1));
		for (int j = 0; j < n; j += i << 1) {
			int w = 1;
			for (int k = 0; k < i; ++k) {
				int tmp = (ll)w * f[j | k | i] % cIz;
				f[j | k | i] = (f[j | k] - tmp + cIz) % cIz;
				f[j | k] = (f[j | k] + tmp) % cIz;
				w = (ll)w * e % cIz;
			}
		}
	}
}

void div_n(const int *A, int *B, int n) {
	const int inv_n = cIz - (cIz - 1) / n;
	for (int i = 0; i < n; ++i) B[i] = (ll)A[i] * inv_n % cIz;
}

void poly_mul(const int *A, const int *B, int *C, int n) {
	static int a[S], b[S];
	init_rev(n);
	std::copy(A, A + n, a);
	std::copy(B, B + n, b);
	NTT(a, n, 0);
	NTT(b, n, 0);
	for (int i = 0; i < n; ++i) a[i] = (ll)a[i] * b[i] % cIz;
	NTT(a, n, 1);
	div_n(a, C, n);
}

int fac[N], ifac[N];

void init_fac(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = (ll)fac[i - 1] * i % cIz;
	ifac[n] = Inv(fac[n]);
	for (int i = n; i; --i) ifac[i - 1] = (ll)ifac[i] * i % cIz;
}
inline int C(int n, int m) {
	if (m < 0 || m > n) return 0;
	return (ll)fac[n] * ifac[m] % cIz * ifac[n - m] % cIz;
}

int main() {
//	FILEIO("matrix")
	static int f[2][S], A[S], B[S];
	int n, m;
	scanf("%d%d", &n, &m);
	init_fac(n + 2);
	int L = getL(2 * n + 1);
	int *pre = f[0], *cur = f[1];
	for (int i = 1; i <= n; ++i) A[i] = ifac[i + 2];
	for (int i = 0; i <= n; ++i) cur[i] = 1;
	for (int i = 2; i <= m; ++i) {
		std::swap(pre, cur);
		for (int j = 0; j <= n; ++j) {
			B[j] = (ll)pre[j] * ifac[j] % cIz;
		}
		std::fill(B + n + 1, B + 2 * n + 1, 0);
		poly_mul(A, B, B, L);
		for (int j = 0; j <= n; ++j) {
			cur[j] = ((ll)pre[j] * (j * (j + 1) / 2 + 1) + (ll)fac[j + 2] * B[j]) % cIz;
		//	printf("f[%d][%d] = %d\n", i, j, cur[j]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i) ans = (ans + (ll)cur[i] * C(n, i)) % cIz;
	printf("%d\n", ans);
	return 0;
}