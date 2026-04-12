#include <iostream>
#include <vector>
#include <string>

using namespace std;

int visit(const vector<vector<int>> &g, vector<bool> &visited, int x, int n)
{
	if (visited[x]) {
		return 0;
	}
	visited[x] = true;
	if (n == g.size()) {
		return 1;
	}
	int ans = 0;
	for (int y : g[x]) {
		if (!visited[y]) {
			ans += visit(g, visited, y, n + 1);
			visited[y] = false;
		}
	}
	return ans;
}

int countPaths(const vector<vector<int>> &g, int s)
{
	int ans = 0;
	vector<bool> visited(g.size(), false);
	return visit(g, visited, s, 1);
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> g(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cout << countPaths(g, 0) << endl;
}
