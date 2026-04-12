#include <iostream>
#include <vector>
using namespace std;

bool IsOneBit(int bits, int i) {
	return (bits & (1 << i)) > 0;
}
int DFS(vector<vector<bool>>& Graph, int Visited, int now) {
	int ans = 0;
	int N = Graph.size();
	if (Visited == (1 << N) - 1) return 1;
	for (int i = 0; i < N; i++) {
		if (Graph[now][i] == 1 && !IsOneBit(Visited, i)) {
			Visited += (1 << i);
			ans += DFS(Graph, Visited, i);
			Visited -= (1 << i);
		}
	}
	return ans;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<bool>> Graph(N, vector<bool>(N, false));

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Graph[a-1][b-1] = true;
		Graph[b-1][a-1] = true;
	}

	int Visited = 1;
	cout << DFS(Graph, Visited, 0) << endl;
}