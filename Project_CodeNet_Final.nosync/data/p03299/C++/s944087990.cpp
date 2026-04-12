#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 105;

int n, h[N];
int p[N], l[N], r[N];
int f[N][2], sz[N], H[N], visit[N][N];
vector<int> G[N];

int binPow(int x, int y) {
	if (!y) return 1;
	int ret = binPow(x, y >> 1); 
	ret = 1LL * ret * ret % mod;
	if (y & 1) ret = 1LL * ret * x % mod; 
	return ret;
}

void dfs(int u) {
	int tmp = sz[u];
	f[u][0] = f[u][1] = 1;
	for (auto v : G[u]) {
		dfs(v), tmp -= sz[v];
		f[u][0] = 1LL * f[u][0] * f[v][0] % mod;
		f[u][1] = 1LL * f[u][1] * (2LL * f[v][0] + f[v][1]) % mod;
	}
	f[u][0] = 2 * f[u][0] % mod;
	f[u][1] = 1LL * f[u][1] * binPow(2, tmp) % mod;
	f[u][1] = (f[u][1] + mod - f[u][0]) % mod;
	f[u][0] = 1LL * f[u][0] * binPow(2, H[u] - 1) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> h[i];
	for (int i = 1; i <= n; ++i) {
		l[i] = i;
		while (l[i] > 1 && h[l[i] - 1] >= h[i]) l[i] = l[l[i] - 1];
	}
	for (int i = n; i >= 1; --i) {
		r[i] = i;
		while (r[i] < n && h[r[i] + 1] >= h[i]) r[i] = r[r[i] + 1];
	}
	for (int i = 1; i <= n; ++i) p[i] = i;
	sort(p + 1, p + 1 + n, [&] (int x, int y) {
		return h[x] < h[y];
	});
	int cnt = 0;
	visit[1][n] = ++cnt, sz[1] = n, H[1] = h[p[1]];
	for (int i = 1; i <= n; ++i) {
		int L = l[p[i]], R = r[p[i]];
		if (visit[L][R]) continue;		
		visit[L][R] = ++cnt, sz[cnt] = R - L + 1;
		H[cnt] = h[p[i]] - max(h[L - 1], h[R + 1]);
		int par = 0;
		if (L > 1 && R < n) {
			if (h[L - 1] > h[R + 1]) par = visit[l[L - 1]][r[L - 1]];
			else par = visit[l[R + 1]][r[R + 1]];
		}
		else if (L > 1) par = visit[l[L - 1]][r[L - 1]];
		else par = visit[l[R + 1]][r[R + 1]];
		G[par].push_back(cnt);
		// cout << cnt << ' ' << par << ' ' << H[cnt] << ' ' << sz[cnt] << ' ' << L << ' ' << R << '\n';
	}
	dfs(1);
	// for (int i = 1; i <= cnt; ++i) cout << f[i][0] << ' ' << f[i][1] << '\n';
	cout << (f[1][0] + f[1][1]) % mod;
}