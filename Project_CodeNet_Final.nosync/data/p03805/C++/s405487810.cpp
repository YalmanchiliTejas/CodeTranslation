#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <set>
#include <queue>

using namespace std;

vector<vector<int>> graph;

int n, m;

int addBit(int mask, int bit) {
	return mask + (1LL << bit);
}

int getBit(int mask, int bit) {
	return (1LL << bit) & mask;
}

int ans = 0;

void dfs(int root, int mask) {
	mask = addBit(mask, root);
	if (mask == (1LL << n) - 1) ++ans;
	for (int i = 0; i < (int) graph[root].size(); ++i) {
		if (!getBit(mask, graph[root][i])) {
			dfs(graph[root][i], mask);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	graph.resize(n);

	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		--l; --r;
		graph[l].push_back(r);
		graph[r].push_back(l);
	}

	dfs(0, 0);

	cout << ans << endl;

	return 0;
}