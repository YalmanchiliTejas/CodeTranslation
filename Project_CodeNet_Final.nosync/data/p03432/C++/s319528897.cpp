#include <bits/stdc++.h>

const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
const int MAXN = 16385;
int f[MAXN];
int fac[MAXN], inv[MAXN];
int C(int a, int b) { return a < b ? 0 : (LL) fac[a] * inv[b] % mod * inv[a - b] % mod; }
int rev[MAXN], wn[MAXN], wt[MAXN], lim, dig;
void init(int sz) {
	lim = 1, dig = -1;
	while (lim < sz) lim <<= 1, ++dig;
	for (int i = 0; i != lim; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << dig;
	const int Wn = pow(3, (mod - 1) / lim); *wn = 1;
	for (int i = 1; i <= lim; ++i) wn[i] = mul(wn[i - 1], Wn);
}
void NTT(int * A, int typ) {
	for (int i = 0; i != lim; ++i) if (i < rev[i]) std::swap(A[i], A[rev[i]]);
	for (int mid = 1; mid != lim; mid <<= 1) {
		const int Wn = lim / mid / 2;
		for (int i = 0, W = 0; i != mid; ++i, W += Wn)
			wt[i] = wn[typ == 1 ? W : lim - W];
		for (int k = 0; k != lim; k += mid << 1) {
			const int * W = wt;
			for (int l = 0; l != mid; ++l) {
				const int X = A[l + k], Y = mul(*W++, A[l + k + mid]);
				reduce(A[l + k] = X + Y - mod);
				reduce(A[l + k + mid] = X - Y);
			}
		}
	}
	if (typ == -1) {
		const int liminv = pow(lim, mod - 2);
		for (int i = 0; i != lim; ++i) A[i] = mul(A[i], liminv);
	}
}
int A[MAXN], B[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i != MAXN; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[mod % i], mod - mod / i);
	}
	for (int i = 2; i != MAXN; ++i) inv[i] = mul(inv[i - 1], inv[i]);
	int n, m; std::cin >> n >> m;
	init(n * 2 + 2);
	for (int i = 1; i <= n; ++i) B[i] = inv[i + 2];
	NTT(B, 1);
	f[0] = 1;
	for (int i = 1; i <= m; ++i) {
		memset(A, 0, lim << 2);
		for (int j = 0; j <= n; ++j) A[j] = mul(f[j], inv[j]);
		NTT(A, 1);
		for (int j = 0; j != lim; ++j) A[j] = mul(A[j], B[j]);
		NTT(A, -1);
		for (int j = 0; j <= n; ++j) A[j] = mul(A[j], fac[j + 2]);
		for (int j = 0; j <= n; ++j)
			reduce(A[j] += mul(f[j], C(j, 2) + j + 1) - mod);
		memcpy(f, A, n + 1 << 2);
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i)
		reduce(ans += mul(f[i], C(n, i)) - mod);
	std::cout << ans << std::endl;
	return 0;
}
