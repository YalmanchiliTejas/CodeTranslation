#include <bits/stdc++.h>
using namespace std;

int n, P, binom[3005][3005], s2[3005][3005];

int power(int a, int x, int P) {
	int ans = 1;
	for (; x; x >>= 1, a = 1ll * a * a % P)
		if (x & 1) ans = 1ll * ans * a % P;
	return ans;
}

int main() {
	scanf("%d%d", &n, &P);
	s2[0][0] = 1;
	for (int i = 0; i <= n + 1; ++i)
		for (int j = binom[i][0] = 1; j <= i; ++j) {
			s2[i][j] = (s2[i - 1][j - 1] + 1ll * s2[i - 1][j] * j) % P;
			binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % P;
		}
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		int e = power(2, n - i, P), pw = 1, s = 0;
		for (int j = 0; j <= i; ++j, pw = 1ll * pw * e % P)
			s = (s + 1ll * s2[i + 1][j + 1] * pw) % P;
		ans = (ans + (i & 1 ? -1ll : 1ll) * s * binom[n][i] % P * power(2, power(2, n - i, P - 1), P)) % P;
	}
	printf("%d\n", (ans + P) % P);
	return 0;
}
