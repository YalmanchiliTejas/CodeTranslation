#include "bits/stdc++.h"

using namespace std;

uint64_t MOD = 1000000007;

#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(x) begin(x),end(x)

using Weight = int64_t;
Weight INF = 1000000000000000000ll;
struct Edge {
	int src, dest; Weight weight;
	bool operator < (const Edge &rhs) const { return weight > rhs.weight; }
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void add_edge(Graph &g, int src, int dest, Weight weight) {
	g[src].push_back(Edge { src, dest, weight });
}

// Dijkstra (Verified: AOJ2005)
void dijkstra(Graph &g, Array &d, int s) {
	d.assign(g.size(), INF);
	d[s] = 0;
	using P = pair<Weight, int>;
	priority_queue<P, vector<P>, greater<P> > que;
	que.push(P(0, s));
	while (!que.empty()) {
		Weight dist = que.top().first;
		int v = que.top().second;
		que.pop();
		if (d[v] < dist) continue;
		REP(i, g[v].size()) {
			Edge e = g[v][i];
			if (d[e.dest] > d[v] + e.weight) {
				d[e.dest] = d[v] + e.weight;
				que.push(P(d[e.dest], e.dest));
			}
		}
	}
}

int main() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	--s;
	--t;
	Graph g(n);
	REP(i, m) {
		int u, v, d;
		cin >> u >> v >> d;
		--u; --v;
		add_edge(g, u, v, d);
		add_edge(g, v, u, d);
	}
	Array d1;
	dijkstra(g, d1, s);
	Array d2;
	dijkstra(g, d2, t);
	Weight dist = d1[t];
	vector<pair<Weight, int>> v1;
	vector<pair<Weight, int>> v2;
	Graph mg1(n);
	Graph mg2(n);
	REP(i, n) {
		if (d1[i] + d2[i] == dist) {
			v1.emplace_back(d1[i], i);
			v2.emplace_back(d2[i], i);
			for (const auto& e : g[i]) {
				if (d1[e.dest] + d2[e.dest] == dist) {
					if (d1[e.dest] < d1[i]) {
						if (d1[e.dest] + e.weight == d1[i]) {
							add_edge(mg1, e.src, e.dest, e.weight);

						}
					}
					else {
						if (d1[i] + e.weight == d1[e.dest]) {

							add_edge(mg2, e.src, e.dest, e.weight);

						}
					}

				}
				
				
			}
		}
	}
	sort(ALL(v1));
	sort(ALL(v2));
	vector<uint64_t> dp1(n, 0);
	vector<uint64_t> dp2(n, 0);
	dp1[s] = 1;
	dp2[t] = 1;
	REP(i, v1.size()) {
		if (!i) continue;
		Weight d;
		int j;
		tie(d, j) = v1[i];
		for (const auto& e : mg1[j]) {
			dp1[j] += dp1[e.dest];
			dp1[j] %= MOD;
		}
	}
	REP(i, v2.size()) {
		if (!i) continue;
		Weight d;
		int j;
		tie(d, j) = v2[i];
		for (const auto& e : mg2[j]) {
			dp2[j] += dp2[e.dest];
			dp2[j] %= MOD;
		}
	}
	uint64_t cnt = dp1[t] * dp1[t];
	cnt %= MOD;
	REP(i, n) {
		if (d1[i] + d2[i] == dist) {
			if (d1[i] == d2[i]) {
				uint64_t mul = dp1[i] * dp2[i];
				mul %= MOD;
				mul *= mul;
				mul %= MOD;
				cnt += MOD - mul;
				cnt %= MOD;
			}
			for (const auto& e : mg2[i]) {
				if (d1[i] * 2 < dist && d1[e.dest] * 2 > dist) {
					uint64_t mul = dp1[i] * dp2[e.dest];
					mul %= MOD;
					mul *= mul;
					mul %= MOD;
					cnt += MOD - mul;
					cnt %= MOD;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}