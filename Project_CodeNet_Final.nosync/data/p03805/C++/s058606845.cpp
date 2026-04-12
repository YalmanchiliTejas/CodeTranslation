#include <bits/stdc++.h>

using namespace std;

int n;
int counter;

void dfs(vector<vector<int>> &G, int s, int depth, vector<bool> &seen) {
	if (depth == n) {

		counter++;
		return;
	}

	for (int i = 0; i < G[s].size(); i++) {
		if (seen[G[s][i]] == true) {
			continue;
		}
		seen[G[s][i]] = true;
		dfs(G, G[s][i], depth+1, seen);
		seen[G[s][i]] = false;

	}

}

int main() {
	int m;
	cin >> n >> m;
	counter = 0;
	vector < vector<int>> G(n + 1);

	//グラフ隣接リスト読み込み
	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int depth = 1;
	vector<bool> seen(n + 1, false);
//	for (int i = 1; i <= n; i++) {
	int i = 1;
//	if (seen[i]) { continue; }
		seen[i] = true;
		dfs(G, i, depth, seen);
//	}

	cout << counter << endl;
	return 0;

}