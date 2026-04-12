#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int P = 1e9 + 7;
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
int power(int x, ll y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
ll cnt; int dp[MAXN];
int n, ans, a[MAXN], b[MAXN];
int main() {
	read(n), ans = 1;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		if (a[i] == 1) {
			cnt += 1;
			a[i] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		int Max = max(a[i - 1], a[i + 1]);
		if (a[i] > Max) {
			cnt += a[i] - Max;
			a[i] = Max;
		}
	}
	ans = power(2, cnt);
	for (int i = 1; i <= n - 1; i++) {
		b[i] = min(a[i], a[i + 1]);
		if (b[i]) b[i]--;
	}
	dp[0] = 1;
	for (int i = 0; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			static int c[MAXN];
			memset(c, 0, sizeof(c));
			for (int k = i + 1, Min = min(b[k], b[i]); k <= j - 1; k++, chkmin(Min, b[k]))
				chkmax(c[k], Min);
			for (int k = j - 1, Min = min(b[k], b[j]); k >= i + 1; k--, chkmin(Min, b[k]))
				chkmax(c[k], Min);
			ll cnt = 0;
			for (int k = i + 1; k <= j - 1; k++) {
				c[k] = b[k] - c[k];
				if (c[k] - c[k - 1] > 0) cnt += c[k] - c[k - 1];
			}
			if (b[i] == 0 && (b[j] != 0 || i != j - 1)) cnt++;
			update(dp[j], 1ll * dp[i] * power(2, cnt) % P);
			if (b[j] == 0) break;
		}
	}
	writeln(1ll * ans * dp[n] % P);
	return 0;
}