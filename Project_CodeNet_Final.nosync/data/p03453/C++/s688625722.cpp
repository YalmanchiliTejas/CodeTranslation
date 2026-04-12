#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;

int n, m, st, en;
vector < pair <int, long long> > ad[N];
long long way[N][2], d[N][2], M = 1e9 + 7;
void djk(int v, int t) {
	set < pair <long long, int> > s;
	s.insert({1, v});
	way[v][t] = 1;
	d[v][t] = 1;
	while (s.size()) {
		int u = s.begin()->second, dis = s.begin()->first;
		s.erase(s.begin());
		for (auto x: ad[u]) {
			int disp = dis + x.second;
			int up = x.first;
			if (!d[up][t] || d[up][t] > disp) {
				s.erase({d[up][t], up});
				d[up][t] = disp;
				way[up][t] = way[u][t];
				s.insert({disp, up});
			}
			else if (disp == d[up][t]) {
				way[up][t] = (way[up][t] + way[u][t]) % M;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		d[i][t]--;
	}
}

int32_t main() {
	cin >> n >> m >> st >> en;
	while (m--) {
		int v, u, w;
		cin >> v >> u >> w;
		ad[v].push_back({u, w});
		ad[u].push_back({v, w});
	}
	djk(st, 1);
	djk(en, 0);
	long long res = (way[en][1] * way[st][0]) % M;
	for (int v = 1; v <= n; v++) {
		for (auto u: ad[v]) {
			int t1 = d[v][1];
			int t2 = d[u.first][0];
			if (t2 + u.second != d[v][0])
				continue;
			if (t1 + u.second != d[u.first][1])
				continue;
			if (t1 + t2 + u.second != d[en][1])
				continue;
			if (abs(t1 - t2) < u.second) {
				res = (res - ((((way[v][1] * way[v][1]) % M) * ((way[u.first][0] * way[u.first][0]) % M)) % M)) % M;
			}
		}
		if (d[v][1] + d[v][0] == d[en][1] && d[v][1] == d[v][0]) {
			res = (res - ((((way[v][0] * way[v][0]) % M) * ((way[v][1] * way[v][1]) % M)) % M)) % M;
		}
	}
	cout << (((res % M) + M) % M);
	return 0;
}
