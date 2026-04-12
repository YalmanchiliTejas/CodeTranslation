#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	bool graph[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = false;
		}
	}
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a][b] = graph[b][a] = true;
	}
	
	int path[n];
	for (int i = 0; i < n; i++) {
		path[i] = i;
	}
	
	int ans = 0;
	do {
		if (path[0] == 0) {
			for (int i = 0; i < n - 1; i++) {
				if (graph[path[i]][path[i + 1]] == false) {
					break;
				}
				if (i == n - 2) {
					ans++;
				}
			}
		} else {
			break;
		}
	} while(next_permutation(path, path + n));
	
	cout << ans << endl;
	return 0;
}