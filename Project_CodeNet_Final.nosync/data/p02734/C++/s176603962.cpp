#include <bits/stdc++.h>
#define LL long long
#define int LL

const int N = 3e3 + 5;
const int mod = 998244353;

int n, s, a[N];
LL ans, f1[N][N], f2[N][N];

signed main() {
	scanf("%lld %lld", &n, &s);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= s; ++j) {
			f2[i][j] = f2[i - 1][j];
			if (j >= a[i]) {
				int t = j - a[i];
				f1[i][j] = f2[i - 1][t];
				if (!t) (f1[i][j] += i) %= mod;
			}
			(f2[i][j] += f1[i][j]) %= mod;
		}
		(ans += f1[i][s] * (n - i + 1)) %= mod;
	}
	printf("%lld", ans);
	return 0;
}
