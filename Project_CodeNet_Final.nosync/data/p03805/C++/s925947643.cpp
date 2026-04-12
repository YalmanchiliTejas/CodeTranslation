#include<iostream>
using namespace std;

const int MAXN = 8;
bool graph[MAXN][MAXN];

int dfs(int v, int N, bool visited[]) {
	bool allV = true;
	for (int i = 0; i < N; i++)if (visited[i] == false)allV = false;
	if (allV)return 1;

	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (graph[v][i] == false || visited[i])continue;
		visited[i] = true;
		ret += dfs(i, N, visited);
		visited[i] = false;
	}
	return ret;
}

int main() {
	int N, M; cin >> N >> M;
	for (int i = 0, a, b; i < M; i++) {
		cin >> a >> b;
		graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
	}

	bool visited[MAXN];
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	visited[0] = true;
	cout << dfs(0, N, visited) << endl;

	return 0;
}