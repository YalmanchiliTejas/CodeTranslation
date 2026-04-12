#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3005;
int n, m, g[N][N], c[N][N];

int read() {
	int w = 0; char ch = getchar();
	while(ch > '9' || ch < '0') ch = getchar();
	while(ch <= '9' && ch >= '0') {
		w = w * 10 + ch - 48;
		ch =getchar();
	}
	return w;
}
int fpow(int a, int m, int MOD) {
	int ans = 1;
	for(; m; m >>= 1) {
		if(m & 1) ans = ans * 1ll * a % MOD;
		a = a * 1ll * a % MOD;
	}
	return ans;
}

int main() {
    n = read(); m = read();
    for(int i = 0; i <= n; i++) {
        g[i][0] = c[i][0] = 1;
    	for(int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % m;
            g[i][j] = (g[i - 1][j - 1] + (j + 1) * 1ll * g[i - 1][j] % m) % m;
    	}
    }
    ll ans = 0;
    for(int i = 0; i <= n; i++) {
    	int powp = fpow(2, fpow(2, n - i, m - 1), m);
    	int d = fpow(2, n - i, m), q = 1, f = 0;
    	for(int j = 0; j <= i; j++) f = (f + g[i][j] * 1ll * q % m) % m, q = q * 1ll * d % m;
        if(i & 1) {
        	ans = (ans + (m - c[n][i]) * 1ll * f % m * powp % m) % m;
        } else ans = (ans + c[n][i] * 1ll * f % m * powp % m) % m;
    }
    printf("%lld\n", ans);
    return 0;
}