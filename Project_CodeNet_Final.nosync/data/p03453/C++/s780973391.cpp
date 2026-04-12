#include <bits/stdc++.h>

using namespace std;

int const N = 1234567;

int const MOD = 1000000007;

int mul(int a, int b) {
	return (int) ((long long) a * b % MOD);
}

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

struct edge {
	int from;
	int to;
	int w;
};

long long const INF = 1LL << 60;

long long d1[N], d2[N];
int w1[N], w2[N];

vector<edge> edges[N];
int n;

void dijkstra(long long *d, int *ways, int start) {
	set<pair<long long, int> > q;
	for (int i = 0; i < n; i++) d[i] = INF;
	d[start] = 0;
	ways[start] = 1;
	q.insert({d[start], start});
	while (!q.empty()) {
		auto e = *q.begin();
		q.erase(q.begin());
		int v = e.second;
		for (auto &e : edges[v]) {
			if (d[e.to] > d[e.from] + e.w) {
				q.erase({d[e.to], e.to});
				d[e.to] = d[e.from] + e.w;
				ways[e.to] = ways[e.from];
				q.insert({d[e.to], e.to});
			} else if (d[e.to] == d[e.from] + e.w) {
				add(ways[e.to], ways[e.from]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	--s;
	--t;
	for (int i = 0; i < m; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		--v;
		--u;
		edges[v].push_back({v, u, w});
		edges[u].push_back({u, v, w});
	}
	dijkstra(d1, w1, s);
	dijkstra(d2, w2, t);
	long long shortest = d1[t];
	int ans = mul(w1[t], w2[s]);
	assert(w1[t] == w2[s]);
	for (int i = 0; i < n; i++) {
		if (shortest == d1[i] + d2[i] && d1[i] == d2[i]) {
			int have = mul(w1[i], w2[i]);
			add(ans, MOD - mul(have, have));
		}
	}
	for (int v = 0; v < n; v++) {
		for (auto &e : edges[v]) {
			if (d1[v] * 2 < shortest && d2[e.to] * 2 < shortest && d1[v] + d2[e.to] + e.w == shortest) {
				int have = mul(w1[v], w2[e.to]);
				add(ans, MOD - mul(have, have));
			}
		}
	}
	cout << ans << endl;
}
