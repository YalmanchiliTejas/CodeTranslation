#include <bits/stdc++.h>
#define N 105

using namespace std;

const int mod = 1e9 + 7;

int n, tot;
int h[N], H[N], f[N][2];

inline int fpm(int x, int y) {
	int res = 1;
	while(y) {
		if(y & 1) res = 1LL * x * res % mod;
		x = 1LL * x * x % mod, y >>= 1;
	}
	return res;
}

void solve(int u, int l, int r) {
	bool flag = false;
	H[u] = h[r];
	for(int i = l; i < r; ++i)
		if(h[i] != h[i + 1]) {
			H[u] = min(H[u], h[i]);
			flag = true;
		}
	
	if(!flag) {
		f[u][0] = fpm(2, r - l + 1) - 2;
		f[u][1] = fpm(2, H[u]);
		return;
	}
	
	f[u][0] = 1, f[u][1] = 2;
	for(int i = l; i <= r; ++i) {
		h[i] -= H[u];
		if(!h[i])
			f[u][0] = (f[u][0] + f[u][0]) % mod;
	}
	
	int las = 1;
	for(int i = l; i <= r; ++i) {
		if(h[i - 1] == 0 && h[i] != 0) las = i;
		if(h[i] != 0 && h[i + 1] == 0) {
			int v = ++tot;
			solve(v, las, i);
			f[u][0] = f[u][0] * (f[v][0] + 2LL * f[v][1]) % mod;
			f[u][1] = 1LL * f[u][1] * f[v][1] % mod;
		}
	}
	
	f[u][0] = (f[u][0] - f[u][1] + mod) % mod;
	f[u][1] = 1LL * f[u][1] * fpm(2, H[u] - 1) % mod;
	
//	cerr << l << ' ' << r << ' ' << H[u] << ' ' << f[u][0] << ' ' << f[u][1] << endl;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &h[i]);
	
	solve(0, 1, n);
	
	int ans = (f[0][0] + f[0][1]) % mod;
	printf("%d\n", ans);
	return 0;
}