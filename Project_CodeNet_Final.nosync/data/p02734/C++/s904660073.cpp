#include <bits/stdc++.h>

using namespace std;

int a[5001];
int f[3001][3001], g[3001][3001], h[3001][3001];
const int mod = 998244353;
int n, s, ans = 0;
int main( ) {
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	f[0][0] = g[0][0] = h[0][0] = 1;
	for (int i = 1; i <= n; i ++) {
	//	g[i][0] = h[i][0] = 1;
		for (int j = s; j >= 0; j --) {
			if (j >= a[i]) {
				f[i][j] = (f[i - 1][j] + f[i - 1][j - a[i]]) % mod;
				g[i][j] = (f[i - 1][j] + f[i - 1][j - a[i]]) % mod;
			}
			else {
				f[i][j] = f[i - 1][j];
				g[i][j] = f[i - 1][j];
			}
		}
		f[i][0] = (f[i][0] + 1) % mod;
		for (int j = 0; j <= s; j ++) h[i][j] = (h[i - 1][j] + f[i][j]) % mod;
	}
	printf("%d\n", h[n][s]);
	return 0;
}
