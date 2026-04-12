#include <bits/stdc++.h>

using namespace std;

const long long INF = 1'000'000'000'000'000'000ll, MOD = 1'000'000'007;

vector<vector<int>> graph, pre, G, ST, TS;
vector<int> U, V, W, fromS, fromT;
vector<long long> dist;
vector<bool> vis;
set<pair<int, int>> used;

int other(int ed, int u) {
	return U[ed] == u ? V[ed] : U[ed];
}

void dijkstra(int s, int t) {
	int n = (int)graph.size();
	dist.assign(n, INF);
	dist[s] = 0;
	priority_queue<pair<long long, int>> pq;
	pq.push({0, s});
	while (!pq.empty()) {
		long long d = -pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (d != dist[u]) {
			continue;
		}
		for (int ed: graph[u]) {
			int v = other(ed, u), w = W[ed];
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pre[v] = {u};
				pq.push({-dist[v], v});
			} else if (dist[u] + w == dist[v]) {
				pre[v].push_back(u);
			}
		}
	}
}

void make_graph(int u) {
	if (vis[u]) {
		return;
	}
	vis[u] = true;
	for (int v: pre[u]) {
		G[u].push_back(v);
		G[v].push_back(u);
		ST[v].push_back(u);
		TS[u].push_back(v);
		make_graph(v);
		used.insert({u, v});
		used.insert({v, u});
	}
}

int calc(int u, vector<int> &vec, const vector<vector<int>> &adj, int base) {
	int &ans = vec[u];
	if (ans != -1) {
		return ans;
	}
	if (u == base) {
		return ans = 1;
	}
	ans = 0;
	for (int v: adj[u]) {
		ans = (ans + calc(v, vec, adj, base)) % MOD;
	}
	return ans;
}

int sq(int x) {
	return (long long)x * x % MOD;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int s, t;
	scanf("%d %d", &s, &t);
	s--, t--;
	U.resize(m);
	V.resize(m);
	W.resize(m);
	graph.assign(n, {});
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--, v--;
		graph[u].push_back(i);
		graph[v].push_back(i);
		U[i] = u, V[i] = v, W[i] = w;
	}
	pre.assign(n, {});
	dijkstra(s, t);
	G.assign(n, {});
	ST = TS = G;
	vis.assign(n, false);
	make_graph(t);
	fromS.assign(n, -1);
	fromT.assign(n, -1);
	int st = calc(t, fromS, TS, s), ts = calc(s, fromT, ST, t);
	int ans = (long long)st * ts % MOD;
	for (int i = 0; i < n; i++) {
		if (2 * dist[i] == dist[t]) {
			ans = (ans + MOD - (long long)sq(fromS[i]) * sq(fromT[i]) % MOD) % MOD;
		}
	}
	for (int i = 0; i < m; i++) {
		if (dist[U[i]] > dist[V[i]]) {
			swap(U[i], V[i]);
		}
		if (!used.count({U[i], V[i]})) {
			continue;
		}
		long long delta = abs(dist[t] - dist[V[i]] - dist[U[i]]);
		if (delta < W[i]) {
			//printf("%d %d %d %d %d %d\n", U[i], V[i], fromS[U[i]], fromT[V[i]], sq(fromS[U[i]]), sq(fromT[V[i]]));
			ans = (ans + MOD - (long long)sq(fromS[U[i]]) * sq(fromT[V[i]]) % MOD) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}