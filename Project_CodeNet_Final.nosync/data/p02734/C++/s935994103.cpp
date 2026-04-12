#include <cstdio>
const int P = 998244353;
int n, m, a[3005], f[3005][3005], ans;
int main(){
	scanf("%d%d", &n, &m);
	for (register int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j){
			if (j == a[i]) f[i][j] = (f[i][j] + i) % P;
			if (j >= a[i]) f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % P;
			if (j == m) ans = (ans + 1ll * f[i][j] * (n - i + 1)) % P;
			f[i][j] = (f[i][j] + f[i - 1][j]) % P;
		}
	printf("%d\n", ans);
}
