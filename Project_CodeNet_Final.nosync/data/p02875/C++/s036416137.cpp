#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
const int N = 11000000;
const int maxn = 10000000;

int mul[N], inv[N];

int Pow(int x, int y) {
	int ans = 1;
	for (int i = 1; i <= y; i *= 2, x = 1LL * x * x % P)
		if (i & y)
			ans = 1LL * ans * x % P;
	return ans;
}

int C(int x, int y) {
	if (y > x)
		return 0;
	if (y < 0)
		return 0;
	return 1LL * mul[x] * inv[y] % P * inv[x - y] % P;
}

int main() {
	mul[0] = 1;
	for (int i = 1; i <= maxn; i++) {
		mul[i] = 1LL * mul[i - 1] * i % P;
	}
	inv[maxn] = Pow(mul[maxn], P - 2);
	for (int i = maxn - 1; i >= 0; i--)
		inv[i] = 1LL * inv[i + 1] * (i + 1) % P;

	int n;
	scanf("%d", &n);

	int ans = 0;
	int ss = C(n, n / 2);

	for (int c = 0; c <= n; c++) {
		if (c >= n / 2) {
			ans = (ans + 1LL * C(n, c) * Pow(2, n - c)) % P;
		}else {
			if (c == 0)
				ss = C(n, n / 2);
			else {
				ss = (ss + C(n - c, n / 2 - c)) % P;
				ss = (ss + C(n - c, n / 2)) % P;
				ss = 1LL * ss * (P + 1) / 2 % P;
				// printf("?? %d\n", ss);
			}
			ans = (ans + 1LL * C(n, c) * ss) % P;
		}
		// int mi = max(0, n / 2 - c);
		// int ma = min(n - c, n / 2);
		// for (int i = mi; i <= ma; i++)
		// 	ans = (ans + 1LL * C(n, c) * C(n - c, i)) % P;
	}
	printf("%d\n", ans);
}
