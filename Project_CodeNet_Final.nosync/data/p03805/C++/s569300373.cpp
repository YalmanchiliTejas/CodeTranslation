#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int	count_root(int N, const Graph &graph, vector<bool> &visited,
		int order, int node)
{
	if (order == N - 1)
		return 1;
	int cnt = 0;
	for (int v : graph.at(node)) {
		if (visited.at(v)) continue;
		visited.at(v) = true;
		cnt += count_root(N, graph, visited, order + 1, v);
		visited.at(v) = false;
	}
	return cnt;
}

int	main()
{
	int	N, M;
	cin >> N >> M;
	Graph	graph(N);
	int	a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		--a, --b;
		graph.at(a).push_back(b);
		graph.at(b).push_back(a);
	}
	vector<bool>	visited(N, false);
	visited.at(0) = true;
	cout << count_root(N, graph, visited, 0, 0) << endl;
}
