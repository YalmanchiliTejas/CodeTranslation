#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(int s, int cnt, int& res, vector<bool>& visited, vector<vector<bool>>& d) {
	if (cnt == visited.size()) { ++res; }

	for (int i = 0; i < d.size(); ++i) {
		if (!d[s][i] || visited[i]) { continue; }

		visited[i] = true;
		dfs(i, cnt + 1, res, visited, d);
		visited[i] = false;
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<bool>> d(N, vector<bool>(N, false));
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		d[a - 1][b - 1] = true;
		d[b - 1][a - 1] = true;
	}

	int res = 0;
	vector<bool> visited(N, false);
	visited[0] = true;
	for (int i = 0; i < N; ++i) {
		if (d[0][i]) {
			visited[i] = true;
			dfs(i, 2, res, visited, d);
			visited[i] = false;
		}
	}

	cout << res << endl;

	return 0;
}
