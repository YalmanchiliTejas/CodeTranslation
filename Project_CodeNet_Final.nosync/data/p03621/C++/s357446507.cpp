#include <bits/stdc++.h>
#define M 10005
#define mod 998244353
typedef long long ll;
char A[M], B[M];
int n, m, len, F[M][M];
ll fac[M], fac_inv[M];
int read() {
	char c = getchar(); int ans = 0;
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') ans = ans * 10 + c - '0', c = getchar();
	return ans;
}
void Write(int x) {
	if (x < 10) putchar(x + '0');
	else Write(x / 10), putchar(x % 10 + '0');
}
ll invs(int x) {return x == 1 ? 1 : (mod - mod / x) * invs(mod % x) % mod;}
ll binom(int x, int y) {return x < y || y < 0 ? 0 : fac[x] * fac_inv[y] % mod * fac_inv[x - y] % mod;}
int main() {
	scanf("%s%s", A + 1, B + 1), len = strlen(A + 1);
	for (int i = 1; i <= len; i++) {
		if (A[i] == '1' && B[i] == '1') n++;
		if (A[i] == '1' && B[i] == '0') m++;
	}
	fac[0] = 1;
	for (int i = 1; i <= len; i++) fac[i] = fac[i - 1] * i % mod; fac_inv[len] = invs(fac[len]);
	for (int i = len; i; i--) fac_inv[i - 1] = fac_inv[i] * i % mod;
	for (int i = 0; i <= m; i++) F[0][i] = fac[i] * fac[i] % mod;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			F[i][j] = ((ll)F[i - 1][j] * (i * j) % mod + (ll)F[i][j - 1] * (j * j)) % mod;
	ll ans = 0;
	for (int i = 0; i <= n; i++)
		ans = (ans + binom(n + m, i) * fac[i] % mod * fac[i] % mod * binom(n, i) % mod * F[n - i][m]) % mod;
	return Write(ans), 0;
}
