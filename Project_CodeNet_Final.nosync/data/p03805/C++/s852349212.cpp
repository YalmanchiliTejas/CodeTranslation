#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int minb = 1000000006;

int path = 0;
int N, M;
vector<vector<int>> G;
vector<int> used;

void dfs(int a) {
	bool h = true;
	for (int i = 0; i < N; i++) {
		if (!used[i])h = false;
	}
	if (h)path++;
	for (int i = 0; i <G[a].size() ; i++) {
		if (used[G[a][i]])continue;
		used[G[a][i]] = true;
		dfs(G[a][i]);
		used[G[a][i]] = false;
	}
}

int main() {
	cin >> N >> M;
	G = vector<vector<int>>(N);
	used = vector<int>(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	used[0] = true;
	dfs(0);
	cout << path << endl;
}