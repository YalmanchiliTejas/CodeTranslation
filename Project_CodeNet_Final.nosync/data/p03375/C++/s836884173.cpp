#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e3;
int n, mod, C[maxn + 3][maxn + 3], S[maxn + 3][maxn + 3];

inline int func(int x) {
	return x < mod ? x : x - mod;
}

int qpow(int a, int b, int m = mod) {
	int c = 1;
	for (; b; b >>= 1, a = 1ll * a * a % m) {
		if (b & 1) c = 1ll * a * c % m;
	}
	return c;
}

void prework(int n) {
	for (int i = 0; i <= n; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = func(C[i - 1][j - 1] + C[i - 1][j]);
		}
	}
	for (int i = 0; i <= n; i++) {
		S[i][0] = 0, S[i][i] = 1;
		for (int j = 1; j < i; j++) {
			S[i][j] = (1ll * S[i - 1][j] * j + S[i - 1][j - 1]) % mod;
		}
	}
}

int main() {
	scanf("%d %d", &n, &mod);
	prework(n + 1);
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		int x = i & 1 ? mod - C[n][i] : C[n][i], s = 0;
		x = 1ll * x * qpow(2, qpow(2, n - i, mod - 1)) % mod;
		for (int j = 0; j <= i; j++) {
			int y = qpow(2, (n - i) * j);
			y = 1ll * y * S[i + 1][j + 1] % mod;
			s = func(s + y);
		}
		ans = (ans + 1ll * x * s) % mod;
	}
	printf("%d\n", ans);
	return 0;
}