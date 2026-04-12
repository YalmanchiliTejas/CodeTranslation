#include "bits/stdc++.h"
using namespace std;
int N, M, A, B, count = 0;
bool G[8][8];

int DFS(int V, int N, bool visited[8]) {
	bool ALL = true;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) ALL = false;
	}
	if (ALL) return 1;
	for (int i = 0; i < N; i++) {
		if (!G[V][i]) continue;
		if (visited[i]) continue;
		visited[i] = true;
		ret += DFS(i, N, visited);
		visited[i] = false;
	}
	return ret;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		G[A - 1][B - 1] = true;
		G[B - 1][A - 1] = true;
	}
	bool visited[8];
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	visited[0] = true;
	cout << DFS(0, N, visited);
}