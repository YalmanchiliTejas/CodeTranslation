#include <iostream>
#include <algorithm>

using namespace std;

int graph_p[9][9];

int dfs(int v, int n, int visited[9]) {
	int res = 1;
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			res = 0;
		}
	}

	if (res == 1)
		return 1;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (graph_p[v][i] == 1 && visited[i]==0) {
			visited[i] = 1;
			cnt += dfs(i, n, visited);
			visited[i] = 0;
		}
	}

	return cnt;
}


int main()
{
	int n, m;
	int visited[9];

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph_p[a-1][b-1] = 1;
		graph_p[b-1][a-1] = 1;
	}

	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}

	visited[0] = 1;

	cout << dfs(0, n, visited) << endl;


    return 0;
}

