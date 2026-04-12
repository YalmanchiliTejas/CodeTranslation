#include "bits/stdc++.h"

using Weight = int;
using Flow = int;
struct Edge {
	int src, dst;
	Weight weight;
	Flow cap;
	Edge() : src(0), dst(0), weight(0) {}
	Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

void add_edge(Graph &g, int a, int b, Weight w = 1) {
	g[a].emplace_back(a, b, w);
	g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, int a, int b, Weight w = 1) { g[a].emplace_back(a, b, w); }

bool operator<(const Edge &e, const Edge &f) { return e.weight > f.weight; }
std::pair<Weight, Edges> prim(const Graph &g, int r = 0) {
	Edges T;
	Weight total = 0;
	std::vector<int> vis(g.size());
	std::priority_queue<Edge> q;
	q.emplace(-1, r, 0);
	while (q.size()) {
		Edge e = q.top();
		q.pop();
		if (vis[e.dst]) continue;
		vis[e.dst] = true;
		total += e.weight;
		if (e.src != -1) T.emplace_back(e);
		for (auto &f : g[e.dst])
			if (!vis[f.dst]) q.emplace(f);
	}
	return std::make_pair(total, T);
}
int main() {
	int N;
	std::cin >> N;
	Graph g(N+1);
	std::vector<std::pair<int, int>> dist_x, dist_y;
	
	for (int i = 1; i <= N; i++) {
		int x, y;
		std::cin >> x >> y;
		dist_x.emplace_back(std::make_pair(x, i));
		dist_y.emplace_back(std::make_pair(y, i));
	}
	std::sort(begin(dist_x), end(dist_x));
	std::sort(begin(dist_y), end(dist_y));

	// add
	for (int i = 1; i < dist_x.size(); i++) {
		auto& p = dist_x[i - 1];
		auto& q = dist_x[i];
		add_edge(g, p.second, q.second, q.first - p.first);
	}
	
	for (int i = 1; i < dist_y.size(); i++) {
		auto& p = dist_y[i - 1];
		auto& q = dist_y[i];
		add_edge(g, p.second, q.second, q.first - p.first);
	}

	std::cout << prim(g, 1).first << std::endl;

	return 0;
}