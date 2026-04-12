#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5, mod = 1e9 + 7;
int n, m, a[maxn + 10], lim;
char s[maxn + 10];
bool fd, fir = 1;
int f[maxn + 10], sum[maxn + 10], ans;
int main() {
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= m; ++i) a[i] = s[i] == 'R';
	if (a[1]) {
		for (int i = 1; i <= m; ++i) a[i] ^= 1;
	}
	for (int i = 1; i <= m; ++i)
		if (a[i]) fd = 1;
	lim = n;
	if (fd) {
		for (int i = 1, cnt = 0; i <= m; ++i)
			if (!a[i]) ++cnt;
			else {
				if (fir) {
					lim = min(lim, cnt % 2 ? cnt : cnt + 1);
					fir = 0;
				} else if (cnt % 2) 
					lim = min(lim, cnt);
				cnt = 0;
			}
		if (n % 2) {
			printf("0"); return 0;
		}
		n /= 2; lim = (lim + 1) / 2;
		f[0] = sum[0] = 1;
		for (int i = 1; i <= n; ++i) {
			if (i <= lim) f[i] = sum[i - 1];
			else f[i] = (sum[i - 1] - sum[i - lim - 1] + mod) % mod;
			sum[i] = (sum[i - 1] + f[i]) % mod;
		}
		for (int i = 1; i <= lim; ++i)
			(ans += 2ll * i * f[n - i] % mod) %= mod;
	} else {
		f[0] = sum[0] = 1;
		for (int i = 1; i <= n; ++i) {
			if (i > 1) f[i] = sum[i - 2];
			sum[i] = (sum[i - 1] + f[i]) % mod;
		}
		ans = 1;
		for (int i = 2; i <= lim; ++i)
			(ans += 1ll * i * f[n - i] % mod) %= mod;
	}
	printf("%d", ans);
}
