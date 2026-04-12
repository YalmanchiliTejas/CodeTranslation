#include <bits/stdc++.h>

typedef long long ll;
const int N = 3054;

int mod, n;
int pw2[N], gw2[N];
int C[N][N], S2[N][N];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}

void init(int n) {
	int i, j;
	for (*pw2 = i = 1; i <= n; ++i) pw2[i] = pw2[i - 1] * 2 % mod;
	for (*gw2 = 2, i = 1; i <= n; ++i) gw2[i] = (ll)gw2[i - 1] * gw2[i - 1] % mod;
	for (**C = i = 1; i <= n; ++i)
		for (*C[i] = j = 1; j <= i; ++j)
			add(C[i][j] = C[i - 1][j], C[i - 1][j - 1]);
	for (**S2 = i = 1; i <= n; ++i)
		for (j = 1; j <= i; ++j)
			S2[i][j] = ((ll)S2[i - 1][j] * j + S2[i - 1][j - 1]) % mod;
}

int solve(int num) {
	int set, rem = n - num, S = 0;
	for (set = num; set >= 0; --set) S = ((ll)S * pw2[rem] + S2[num + 1][set + 1]) % mod;
	return (ll)S * gw2[rem] % mod * C[n][num] % mod;
}

int main() {
	int i; ll ans = 0;
	scanf("%d%d", &n, &mod), init(n + 1);
	for (i = 0; i <= n; ++i) i & 1 ? ans -= solve(i) : ans += solve(i);
	ans %= mod, printf("%d\n", int(ans + (ans >> 63 & mod)));
	return 0;
}