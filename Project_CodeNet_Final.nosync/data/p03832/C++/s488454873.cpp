#include <cstdio>
const int MAXN = 1000 + 5, mod = 1e9 + 7;
typedef long long ll;
inline int addmod(int a, int b) { return (a + b) % mod; }
inline int mulmod(ll a, int b) { return (a * b) % mod; }
inline int powmod(int a, int x) {
	ll cur = a, res = 1;
	while(x) {
		if(x & 1) res = (res * cur) % mod;
		x >>= 1;
		cur = (cur * cur) % mod;
	}
	return (int)res;
}
int fac[MAXN], inv_fac[MAXN];
inline int com(int n, int m) {
	return mulmod(fac[n], mulmod(inv_fac[n - m], inv_fac[m]));
}
int f[MAXN][MAXN], g[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, a, b, c, d;
int solve(int n_, int i) {
	if(n_ == 0) return 1;
	if(i > b) return 0;
	if(vis[n_][i]) return f[n_][i];
	int res = solve(n_, i + 1);
	for(int j = c; j <= d && i * j <= n_; j++) {
		res = addmod(res, mulmod(mulmod(com(n_, i * j), mulmod(g[i][j], inv_fac[j])), solve(n_ - i * j, i + 1)));
	}
	vis[n_][i] = true;
	return f[n_][i] = res;
}
int main() {
	fac[0] = 1; inv_fac[0] = powmod(fac[0], mod - 2);
	for(int i = 1; i < MAXN; i++) {
		fac[i] = mulmod(fac[i - 1], i);
		inv_fac[i] = powmod(fac[i], mod - 2);
	}
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	for(int i = a; i <= b; i++) {
		g[i][0] = 1;
		for(int j = 1; j <= d && i * j <= n; j++) g[i][j] = mulmod(com(i * j, i), g[i][j - 1]);
	}
	printf("%d\n", solve(n, a));
	return 0;
}