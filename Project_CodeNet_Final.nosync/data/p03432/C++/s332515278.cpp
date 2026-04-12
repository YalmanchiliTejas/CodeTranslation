#include<bits/stdc++.h>
using namespace std;
const int MAXN = 16384;
const int MAXM = 205;
const int P = 998244353;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
namespace NTT {
	const int MAXN = 262144;
	const int P = 998244353;
	const int G = 3;
	int power(int x, int y) {
		if (y == 0) return 1;
		int tmp = power(x, y / 2);
		if (y % 2 == 0) return 1ll * tmp * tmp % P;
		else return 1ll * tmp * tmp % P * x % P;
	}
	int N, Log, home[MAXN];
	void NTTinit() {
		for (int i = 0; i < N; i++) {
			int ans = 0, tmp = i;
			for (int j = 1; j <= Log; j++) {
				ans <<= 1;
				ans += tmp & 1;
				tmp >>= 1;
			}
			home[i] = ans;
		}
	}
	void NTT(int *a, int mode) {
		for (int i = 0; i < N; i++)
			if (home[i] < i) swap(a[i], a[home[i]]);
		for (int len = 2; len <= N; len <<= 1) {
			int delta;
			if (mode == 1) delta = power(G, (P - 1) / len);
			else delta = power(G, P - 1 - (P - 1) / len);
			for (int i = 0; i < N; i += len) {
				int now = 1;
				for (int j = i, k = i + len / 2; k < i + len; j++, k++) {
					int tmp = a[j];
					int tnp = 1ll * a[k] * now % P;
					a[j] = (tmp + tnp) % P;
					a[k] = (tmp - tnp + P) % P;
					now = 1ll * now * delta % P;
				}
			}
		}
		if (mode == -1) {
			int inv = power(N, P - 2);
			for (int i = 0; i < N; i++)
				a[i] = 1ll * a[i] * inv % P;
		}
	}
	void times(int *a, int *b, int *c, int limit) {
		N = 1, Log = 0;
		while (N < 2 * limit) {
			N <<= 1;
			Log++;
		}
		for (int i = limit; i < N; i++)
			a[i] = b[i] = 0;
		NTTinit();
		NTT(a, 1);
		NTT(b, 1);
		for (int i = 0; i < N; i++)
			c[i] = 1ll * a[i] * b[i] % P;
		NTT(c, -1);
	}
}
int fac[MAXN], inv[MAXN];
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
int binom(int x, int y) {
	if (y > x) return 0;
	else return 1ll * fac[x] * inv[y] % P * inv[x - y] % P;
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % P;
	inv[n] = power(fac[n], P - 2);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1ll) % P;
}
int n, m, ans, dp[MAXM][MAXN];
int main() {
	read(n), read(m);
	init(n + 2), dp[0][0] = 1;
	for (int i = 1; i <= m; i++) {\
		static int a[MAXN], b[MAXN];
		for (int j = 0; j <= n; j++) {
			a[j] = 1ll * dp[i - 1][j] * inv[j] % P;
			if (j == 0) b[0] = 0;
			else b[j] = inv[j + 2];
		}
		NTT :: times(a, b, dp[i], n + 1);
		for (int j = 0; j <= n; j++) {
			dp[i][j] = 1ll * dp[i][j] * fac[j + 2] % P;
			update(dp[i][j], 1ll * dp[i - 1][j] * (1 + binom(j + 1, 2)) % P);
		}
	}
	for (int i = 0; i <= n; i++)
		update(ans, 1ll * dp[m][i] * binom(n, i) % P);
	writeln(ans);
	return 0;
}