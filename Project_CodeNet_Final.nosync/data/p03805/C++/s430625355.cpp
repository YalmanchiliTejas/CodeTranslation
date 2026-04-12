// https://atcoder.jp/contests/abc054/tasks/abc054_c

#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

int dfs(const vector<vector<int>>& edges, int current, unordered_set<int>& visited) {
	visited.insert(current);
	if (visited.count(current) > 0 && visited.size() == edges.size()) {
		visited.erase(current);
		return 1;
	}
	int res = 0;
	for (int edge : edges[current]) {
		if (visited.count(edge) > 0) {
			continue;
		}
		res += dfs(edges, edge, visited);
	}
	visited.erase(current);
	return res;
}

int main (int argc, char* argv[]) {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> edges(n);
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		from--; to--;
		edges[from].push_back(to);
		edges[to].push_back(from);
	}

	unordered_set<int> visited;
	cout << dfs(edges, 0, visited) << endl;
}
