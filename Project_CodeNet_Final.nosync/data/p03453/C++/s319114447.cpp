#include <bits/stdc++.h>

using pil = std::pair<long long, int>;
constexpr long long mod{1000000007};

struct Node {
	// いずれも0:s→t、1:t→s
	long long path_num[2]{}, distance[2]{-1, -1};
	std::list<std::pair<int, long long>> edges;
};
int n, m, s, t;
std::vector<Node> graph;

void dijkstra(int, int);
long long calcNum(int, int);
long long pow2(long long);

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	s--; t--;
	graph.resize(n);
	for (int i{}; i < m; i++)
	{
		int u, v;
		long long d;
		scanf("%d%d%lld", &u, &v, &d);
		u--; v--;
		graph[u].edges.push_back({v, 2 * d});
		graph[v].edges.push_back({u, 2 * d});
	}
	dijkstra(s, 0);
	dijkstra(t, 1);

	graph[s].path_num[0] = graph[t].path_num[1] = 1;
	calcNum(t, 0);
	calcNum(s, 1);
	
	const long long encount_time{graph[t].distance[0] / 2};
	long long encount_combi{};
	for (int i{}; i < n; i++)
	{
		if (!graph[i].path_num[0] || graph[i].distance[0] > encount_time) continue;
		// 以下、頂点iが最短経路上に存在するかつ頂点sのencount_time閉近傍内の場合のみ
		if (graph[i].distance[0] == encount_time && graph[i].distance[1] == encount_time)
		{
			encount_combi = (encount_combi + pow2(graph[i].path_num[0] * graph[i].path_num[1] % mod)) % mod;
			continue;
		}
		// 以下、頂点iは頂点sのencount_time近傍内
		for (auto& e: graph[i].edges)
		{
			if (!graph[e.first].path_num) continue;
			int& dir{i}, rev{e.first};
			// 以下、revは最短経路上に存在
			if (graph[rev].distance[1] >= encount_time) continue;
			// 以下、revはtのencount_time近傍上に存在
			if (graph[dir].distance[0] + e.second != graph[rev].distance[0]) continue;
			// 辺(dir,rev)を通る最短経路が存在
			encount_combi = (encount_combi + pow2(graph[dir].path_num[0] * graph[rev].path_num[1] % mod)) % mod;
		}
	}
	printf("%lld\n", (pow2(graph[t].path_num[0]) % mod + mod - encount_combi) % mod);

	return 0;
}

void dijkstra(int from, int direct)
{
	std::priority_queue<pil, std::vector<pil>, std::greater<pil>> pq;
	pq.push({0, from});
	while (!pq.empty())
	{
		pil dist{pq.top()};
		pq.pop();
		if (graph[dist.second].distance[direct] >= 0) continue;
		graph[dist.second].distance[direct] = dist.first;
		for (auto& e: graph[dist.second].edges)
			if (graph[e.first].distance[direct] < 0)
				pq.push({dist.first + e.second, e.first});
	}
	return;
}

long long calcNum(int index, int direct)
{
	long long& path_num{graph[index].path_num[direct]};
	if (path_num > 0) return path_num;
	for (auto& e: graph[index].edges)
		if (graph[e.first].distance[direct] + e.second == graph[index].distance[direct])
			path_num = (path_num + calcNum(e.first, direct)) % mod;
	return path_num;
}

long long pow2(long long x) { return x * x % mod; }