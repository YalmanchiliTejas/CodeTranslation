#include <bits/stdc++.h>
using namespace std;
const int maxn = 3500;
int n, mod, ans;
int c[maxn + 10][maxn + 10], s[maxn + 10][maxn + 10];
int a[maxn + 10], b[maxn * maxn + 10];

int fpow(int x, int y, int mod) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1ll * ans * x % mod;
		y >>= 1; x = 1ll * x * x % mod;
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &mod);
	c[0][0] = s[0][0] = 1;
	for (int i = 1; i <= maxn; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
			s[i][j] = (1ll * s[i - 1][j] * j + s[i - 1][j - 1]) % mod;
		}
	}
	for (int i = 0; i <= n; ++i)
		a[i] = fpow(2, fpow(2, i, mod - 1), mod);
	b[0] = 1;
	for (int i = 1; i <= maxn * maxn; ++i)
		b[i] = b[i - 1] * 2 % mod;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= i; ++j) {
			int w = 1ll * c[n][i] * s[i + 1][j + 1] % mod;
			w = 1ll * w * b[(n - i) * j] % mod;
			w = 1ll * w * a[n - i] % mod;
			if (i & 1) ans = (ans - w + mod) % mod;
			else ans = (ans + w) % mod;
		}
	printf("%d", ans);
}

