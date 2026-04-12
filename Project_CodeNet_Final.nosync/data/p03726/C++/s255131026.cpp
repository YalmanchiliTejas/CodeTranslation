#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e5;
vector<int> graph[N];

int dfs(int u, int par) {
	int sum = 0;
	for (auto v : graph[u]) if (v != par) {
		int x = dfs(v, u);
		if (x == 2) return 2;
		sum += x;
	}
	if (sum > 1) return 2;
	if (sum == 1) return 0;
	return 1;
}

int main() {
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v; --u; --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cout << (dfs(0, -1) != 0 ? "First" : "Second") << endl;
	return 0;
}
