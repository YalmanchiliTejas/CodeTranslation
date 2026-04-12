#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SIZE(a) ((int)(a).size())

const int N = 100005;
const int mod = 1000*1000*1000 + 7;
const ll linf = 2e18;

int n, m, s, t;
vector<pair<int,int>> g[N];
ll dist[2][N];
int cnt[2][N];

void goDist(int v, int id) {
	set<pair<ll,int>> s;
	REP(i, n) dist[id][i] = linf, cnt[id][i] = 0;
	dist[id][v] = 0;
	cnt[id][v] = 1;
	s.insert({0, v});
	while (!s.empty()) {
		v = s.begin()->second;
		s.erase(s.begin());
		for (auto& item : g[v]) {
			int to = item.first;
			int c = item.second;
			if (dist[id][to] > dist[id][v] + c) {
				s.erase({dist[id][to], to});
				dist[id][to] = dist[id][v] + c;
				cnt[id][to] = 0;
				s.insert({dist[id][to], to});
			}
			if (dist[id][to] == dist[id][v] + c) {
				cnt[id][to] = (cnt[id][to] + cnt[id][v]) % mod;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	cin >> s >> t;
	--s; --t;
	vector<tuple<int,int,int>> edges;
	REP(i, m) {
		int x, y, c;
		cin >> x >> y >> c;
		--x; --y;
		g[x].emplace_back(y, c);
		g[y].emplace_back(x, c);
		edges.emplace_back(x, y, c);
	}
	goDist(s, 0);
	goDist(t, 1);
	int result = (1LL*cnt[0][t]*cnt[1][s]) % mod;
	ll d = dist[0][t];
	REP(i, n) if (dist[0][i] + dist[1][i] == d && i != s && i != t) {
		if (dist[0][i] == dist[1][i]) {
			int now = (1LL*cnt[0][i]*cnt[1][i]) % mod;
			now = (1LL*now*now) % mod;
			result = (result + mod - now) % mod;
		}
	}
	for (auto& edge : edges) {
		int x, y, c;
		tie(x, y, c) = edge;
		if (dist[0][x] + dist[1][y] + c != d) swap(x, y);
		if (dist[0][x] + dist[1][y] + c == d) {
			if (d <= 2*dist[0][x] || d <= 2*dist[1][y]) continue;
			int now = (1LL*cnt[0][x]*cnt[1][y]) % mod;
			now = (1LL*now*now) % mod;
			result = (result + mod - now) % mod;
		}
	}

	cout << result << '\n';
	return 0;
}