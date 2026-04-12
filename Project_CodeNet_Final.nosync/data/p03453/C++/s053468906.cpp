#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 3, INF = 2000ll * 1000 * 1000 * MAXN + 3, D = 1000 * 1000 * 1000 + 7, MAXM = 200 * 1000 + 3;













int n, m, s, t, d[2 + 1][MAXN], cnt[2 + 1][MAXN], w[MAXM], e[MAXM], ans;
vector<int> g[MAXN];
set<pii> p;


void dij(int x, int y) {
	fill(d[y], d[y] + n, INF);
	p.insert({0, x});
	d[y][x] = 0;
	cnt[y][x] = 1;
	while (!p.empty()) {
		int f = p.begin() -> second;
		p.erase(p.begin());
		for (auto i : g[f]) {
			int z = f ^ e[i];
			if (d[y][f] + w[i] < d[y][z]) {
				p.erase({d[y][z], z});
				d[y][z] = d[y][f] + w[i];
				p.insert((pii){d[y][z], z});
				cnt[y][z] = cnt[y][f];
			} else if (d[y][f] + w[i] == d[y][z]) cnt[y][z] = (cnt[y][z] + cnt[y][f]) % D;
		}
	}
}



int32_t main() {
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v >> w[i];
		g[--u].push_back(i), g[--v].push_back(i);
		e[i] = u ^ v;
	}
	s--, t--;
	dij(s, 0), dij(t, 1);
	ans = cnt[0][t] * cnt[1][s] % D;
	int q = d[0][t];
	for (int i = 0; i < n; i++) {
		int a = cnt[0][i], x = d[0][i], o = cnt[1][i];
		for (auto j : g[i]) {
			int zz = e[j] ^ i;
			int y = d[1][zz], b = cnt[1][zz];
			if (x + w[j] != d[0][zz] || y + w[j] != d[1][i] || x + y + w[j] != q || abs(x - y) >= w[j]) continue;
			ans = ((ans - a * b % D * a % D * b % D) + D) % D;
		}
		if (q == d[0][i] + d[1][i] && d[0][i] == d[1][i]) ans = ((ans - a * o % D * a % D * o % D) + D) % D;
	}
	cout << ans;
	return 0;
}