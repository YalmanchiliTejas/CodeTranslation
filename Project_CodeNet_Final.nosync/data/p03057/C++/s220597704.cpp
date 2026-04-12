#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
int n, m;
char s[MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int main() {
	read(n), read(m);
	scanf("%s", s + 1);
	bool same = true;
	for (int i = 1; i <= m; i++)
		if (s[i] != s[1]) same = false;
	if (same) {
		static int dp[MAXN], sum[MAXN];
		dp[1] = sum[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = sum[i - 2];
			sum[i] = (sum[i - 1] + dp[i]) % P;
		}
		int ans = (sum[n - 1] + 1) % P;
		for (int i = 2, j = n - 1; i <= n; i++, j--)
			update(ans, sum[j]);
		printf("%d\n", ans);
		return 0;
	}
	if (n & 1) {
		puts("0");
		return 0;
	}
	int Min = n - (n - 1) % 2;
	int last = 0;
	for (int i = 1; i <= m; i++)
		if (s[i] != s[1]) {
			int len = i - last - 1;
			if (last == 0) chkmin(Min, len + 1);
			if (len % 2 == 1) chkmin(Min, len);
			last = i;
		}
	static int dp[MAXN], sum[MAXN];
	dp[1] = sum[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 1) {
			dp[i] = sum[i - 2];
			update(dp[i], P - sum[max(i - Min - 3, 0)]);
		}
		sum[i] = (sum[i - 1] + dp[i]) % P;
	}
	int ans = (sum[n - 1] - sum[max(n - Min - 2, 0)] + P) % P;
	for (int i = 2, j = n - 1; i <= n && j >= n - Min - 2; i++, j--)
		update(ans, (sum[j] - sum[max(n - Min - 2, 0)] + P) % P);
	printf("%d\n", ans);
	return 0;
}