#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Graph;
vector<bool> seen;

int dfs(int s, int n) {
	if (n == 0) return 1;
	int ret = 0;
	for (auto i : Graph[s]) {
		if (seen[i]) continue;
		seen[i] = true;
		ret += dfs(i, n-1);
		seen[i] = false;
	}
	return ret;
}

int main() {
	int N, M;
	cin >> N >> M;

	Graph = vector<vector<int>>(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Graph[a-1].push_back(b-1);
		Graph[b-1].push_back(a-1);
	}

	seen = vector<bool>(N);
	for (int i = 0; i < N; i++) seen[i] = false;
	seen[0] = true;
	cout << dfs(0, N-1) << endl;
}
