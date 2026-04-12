#include <bits/stdc++.h>

const int mod = 1000000007;
const int MAXN = 1010;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int f[MAXN], g[MAXN];
int n, A, B, C, D;
int fac[MAXN], inv[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i != MAXN; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[mod % i], mod - mod / i);
	}
	for (int i = 2; i != MAXN; ++i)
		inv[i] = mul(inv[i - 1], inv[i]);
	std::cin >> n >> A >> B >> C >> D;
	f[0] = 1;
	for (int i = A; i <= B; ++i) {
		memset(g, 0, sizeof g);
		for (int j = C; j <= D; ++j) {
			int sz = i * j, co = pow(inv[i], j, inv[j]);
			for (int k = sz; k <= n; ++k)
				reduce(g[k] += mul(f[k - sz], co) - mod);
		}
		for (int j = 0; j <= n; ++j) reduce(f[j] += g[j] - mod);
	}
	std::cout << mul(f[n], fac[n]) << std::endl;
	return 0;
}
