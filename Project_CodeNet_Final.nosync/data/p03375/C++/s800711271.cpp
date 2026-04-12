#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
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
int n, ans, P;
int fac[MAXN], inv[MAXN], dp[MAXN][MAXN];
int c(int x, int y) {
	if (y > x) return 0;
	else return 1ll * fac[x] * inv[y] % P * inv[x - y] % P;
}
void update(int &x, int y) {
	x = (x + y) % P;
}
int power(int x, int y, int P) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2, P);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
int getdp(int x) {
	int mul = power(2, power(2, n - x, P - 1), P);
	int chs = power(2, n - x, P), now = 1, ans = 0;
	for (int i = 0; i <= x; i++) {
		update(ans, 1ll * dp[x][i] * now % P);
		now = 1ll * now * chs % P;
	}
	return 1ll * mul * ans % P;
}
int main() {
	read(n), read(P);
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % P;
	inv[n] = power(fac[n], P - 2, P);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1ll) % P;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= i; j++) {
		if (j) dp[i][j] += dp[i - 1][j - 1];
		update(dp[i][j], dp[i - 1][j] * (j + 1ll) % P);
	}
	for (int i = 0; i <= n; i++)
		if (i & 1) update(ans, 1ll * (P - c(n, i)) * getdp(i) % P);
		else update(ans, 1ll * c(n, i) * getdp(i) % P);
	writeln(ans);
	return 0;
}