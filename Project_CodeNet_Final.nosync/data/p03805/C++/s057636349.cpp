#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int edge[9][9];
bool visited[9];

int dfs(int now) {
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			flag = false;
		}
	}
	if (flag) {
		return 1;
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (edge[now][i] && !visited[i]) {
			visited[i] = true;
			res += dfs(i);
			visited[i] = false;
		}
	}
	return res;
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			edge[i][j] = 0;
		}
	}

	for (int i = 0; i < 9; i++) {
		visited[i] = false;
	}

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a][b] = 1;
		edge[b][a] = 1;
	}
	
	visited[1] = true;
	int ans = dfs(1);
	cout << ans << endl;

	return 0;
}
