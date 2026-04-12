#include <iostream>
#include <vector>

using namespace std;

int N;
bool edge[9][9];
bool visited[9];

int dfs(int v, int c) {
	if (visited[v]) return 0;
	if (c == N) return 1;
	visited[v] = true;
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (!edge[v][i]) continue;
		sum += dfs(i, c + 1);
	}
	visited[v] = false;
	return sum;
}

int main(int argc, char *argv[]) {
	cin >> N;
	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		edge[a][b] = edge[b][a] = true;
	}

	cout << dfs(1, 1) << endl;
	return 0;
}