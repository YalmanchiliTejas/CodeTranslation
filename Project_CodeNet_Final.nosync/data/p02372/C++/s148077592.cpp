#include <bits/stdc++.h>

struct Edge {
	int to;
	int64_t dist{1};

	// int64_t cost;
	// int from;
	// int rev_i;
};

std::tuple<int, int, decltype(Edge::dist)> calcTreeDiameter(const std::vector<std::vector<Edge>>& edges)
{
	using Dist = decltype(Edge::dist);
	using pid = std::pair<int, Dist>;

	pid one_side{0, 0};
	std::stack<pid> dfs;
	dfs.push(one_side);
	std::vector<bool> visited(edges.size());

	while (!dfs.empty())
	{
		auto now{dfs.top()};
		dfs.pop();
		visited[now.first] = true;
		if (now.second > one_side.second)
			one_side = now;
		for (auto& e: edges[now.first])
			if (!visited[e.to])
				dfs.push({e.to, now.second + e.dist});
	}
	pid another_side{one_side.first, 0};
	dfs.push(another_side);
	std::fill(visited.begin(), visited.end(), false);
	while (!dfs.empty())
	{
		auto now{dfs.top()};
		dfs.pop();
		visited[now.first] = true;
		if (now.second > another_side.second)
			another_side = now;
		for (auto& e: edges[now.first])
			if (!visited[e.to])
				dfs.push({e.to, now.second + e.dist});
	}
	return std::make_tuple(one_side.first, another_side.first, another_side.second);
}

using ve = std::vector<Edge>;
using vve = std::vector<ve>;

vve graph;
void calcDist(int, std::vector<int64_t>&);

int main()
{
	int n;
	scanf("%d", &n);
	graph.resize(n);
	for (int i{}; i < n - 1; i++)
	{
		int s, t;
		int64_t w;
		scanf("%d%d%lld", &s, &t, &w);
		graph[s].push_back({t, w});
		graph[t].push_back({s, w});
	}
	auto dia{calcTreeDiameter(graph)};
	std::vector<int64_t> dist0(n, LLONG_MIN), dist1(n, LLONG_MIN);
	calcDist(std::get<0>(dia), dist0);
	calcDist(std::get<1>(dia), dist1);

	for (int i{}; i < n; i++)
		printf("%lld\n", std::max(dist0[i], dist1[i]));

	return 0;
}

void calcDist(int source, std::vector<int64_t>& dist)
{
	dist[source] = 0;
	std::stack<int> dfs;
	dfs.push(source);
	std::vector<bool> visited(dist.size());
	while (!dfs.empty())
	{
		auto now{dfs.top()};
		dfs.pop();
		visited[now] = true;
		for (auto& next: graph[now])
			if (!visited[next.to])
			{
				dist[next.to] = dist[now] + next.dist;
				dfs.push(next.to);
			}
	}
}
