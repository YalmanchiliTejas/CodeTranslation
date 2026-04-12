#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#define INF (1<<30)
#define P pair<int,int>
using namespace std;

void dfs(int n, vector<vector<P>>& G, vector<int>& dist) {
	for (P p : G[n]) {
		int next = p.first, cost = p.second;
		if (dist[next] == INF) {
			dist[next] = dist[n] + cost;
			dfs(next, G, dist);
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int n; cin >> n;
	int u, v;
	vector<vector<P>> G(n);
	vector<int> dist(n,INF),dist_u(n,INF),dist_v(n,INF);
	for (int i = 0; i < n - 1; i++) {
		int s, t, w; cin >> s >> t >> w;
		G[s].emplace_back(make_pair(t, w));
		G[t].emplace_back(make_pair(s, w));
	}

	dist[0] = 0;
	dfs(0, G, dist);
	auto maxIt = max_element(dist.begin(), dist.end());
	u = distance(dist.begin(), maxIt);

	dist_u[u] = 0;
	dfs(u, G, dist_u);
	maxIt = max_element(dist_u.begin(), dist_u.end());
	v = distance(dist_u.begin(), maxIt);

	dist_v[v] = 0;
	dfs(v, G, dist_v);
	for (int i = 0; i < n; i++) {
		cout << max(dist_u[i], dist_v[i]) << endl;
	}
}