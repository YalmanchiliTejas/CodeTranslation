#include <bits/stdc++.h>

typedef long long LL;

const int N = 3e3;

int n, p, s[N + 5][N + 5], c[N + 5][N + 5];

int power(int x, int k, int mod) {
	int ans = 1;
	for (; k >= 1; k >>= 1, x = (LL)x * x % mod) {
		if (k & 1) {
			ans = (LL)ans * x % mod;
		}
	}
	return ans;
}
void init(int n) {
	c[0][0] = s[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
			s[i][j] = (s[i - 1][j - 1] + (LL)j * s[i - 1][j] % p) % p;
		}
	}
}
int main() {
	scanf("%d%d", &n, &p);
	init(n + 1);
	int ans = 0;
	for (int sgn = 1, i = 0; i <= n; i++, sgn = p - sgn) {
		int sum = 0, pw0 = power(2, n - i, p);
		for (int cur = 1, j = 0; j <= i; cur = (LL)cur * pw0 % p, j++) {
			sum = (sum + (LL)s[i + 1][j + 1] * cur % p) % p;
		}
		ans = (ans + (LL)sgn * c[n][i] % p * sum % p * power(2, power(2, n - i, p - 1), p) % p) % p;
	}
	printf("%d\n", ans);
	return 0;
}