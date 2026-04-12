#include <bits/stdc++.h>
typedef long long LL;

const int N = 8100, M = 210, p = 998244353, G = 3, invG = (p + 1) / 3;

int A[N << 2], B[N << 2], fac[N], inv[N], rev[N << 2], f[N][M], n, m;

int add(int x, int y) { return x + y >= p ? x + y - p : x + y; }
int sub(int x, int y) { return x - y < 0 ? x - y + p : x - y; }
int inc(int &x, int y) { return x = add(x, y); }
int del(int &x, int y) { return x = sub(x, y); }
int mul(int x, int y) { return 1LL * x * y % p; }

int ksm(int x, int y) {
	int res = 1;
	for (; y; y >>= 1, x = mul(x, x)) if (y & 1) res = mul(res, x);
	return res;
}

void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; ++ i) fac[i] = mul(fac[i - 1], i);
	inv[n] = ksm(fac[n], p - 2);
	for (int i = n - 1; ~i; -- i) inv[i] = mul(inv[i + 1], i + 1); 
}

int C(int n, int m) { return m > n ? 0 : mul(fac[n], mul(inv[m], inv[n - m])); }

void reverse(int *A, int limit) {
	for (int i = 1; i < limit; ++ i) rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? limit >> 1 : 0);
	for (int i = 1; i < limit; ++ i) if (i < rev[i]) std::swap(A[i], A[rev[i]]);
}

void NTT(int *A, int limit, int opt) {
	reverse(A, limit);
	for (int mid = 1; mid < limit; mid <<= 1) {
		int len = mid << 1;
		int w = ksm(opt == 1 ? G : invG, (p - 1) / len);
		for (int i = 0; i < limit; i += len) {
			int W = 1;
			for (int j = i; j < i + mid; ++ j, W = (LL)W * (LL)w % p) {
				int x = A[j], y = (LL)A[j + mid] * (LL)W % p;
				A[j] = add(x, y); A[j + mid] = sub(x, y);
			}
		}
	}
	if (opt == 1) return;
	int inv = ksm(limit, p - 2);
	for (int i = 0; i < limit; ++ i) A[i] = ((LL)A[i] * (LL)inv) % p;
}

void MUL(int *a, int n, int *b, int m) {
	int len = n + m, limit = 1;
	while (limit <= len) limit <<= 1;
	NTT(a, limit, 1), NTT(b, limit, 1);
	for (int i = 0; i < limit; ++ i) a[i] = ((LL)a[i] * (LL)b[i]) % p;
	NTT(a, limit, -1);
}

void Get(int j) {
	memset(A, 0, sizeof(A)), memset(B, 0, sizeof(B));
	for (int i = 1; i <= n; ++ i) A[i] = inv[i + 2];
	for (int i = 0; i <= n; ++ i) B[i] = mul(inv[i], f[i][j - 1]);
	for (int i = 0; i <= n; ++ i) inc(f[i][j], mul(f[i][j - 1], add(i + 1, C(i, 2))));
	MUL(A, n + 1, B, n + 1);
	for (int i = 1; i <= n; ++ i) inc(f[i][j], mul(A[i], fac[i + 2]));
}

signed main() {
	std::cin >> n >> m;
	init(N - 1), f[0][0] = 1;
	for (int i = 1; i <= m; ++ i) Get(i);
	int ans = 0;
	for (int i = 0; i <= n; ++ i) inc(ans, mul(C(n, i), f[i][m]));
	std::cout << ans << std::endl;
	return 0;
}