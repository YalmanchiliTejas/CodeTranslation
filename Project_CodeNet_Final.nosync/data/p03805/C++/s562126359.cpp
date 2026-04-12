#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <tuple>
#include <regex>
#include <map>

using namespace std;
using ull = unsigned long long;
using ll = long long;

int dfs(int v, int N, vector<bool>& visited, const vector<vector<bool>>& Path) {
	// 全部訪問済みなら返す。
	if (all_of(cbegin(visited), cend(visited), [](auto x) {
		return x;
	})) {
		return 1;
	}

	int ans = 0;

	for (size_t i = 0; i < N; i++) {
		// 訪問済みの頂点にはたどらない
		if (visited[i]) {
			continue;
		}
		// 経路がない頂点にはたどらない
		if (!Path[v][i]) {
			continue;
		}

		// 訪問済みとしてから再帰する
		visited[i] = true;
		ans += dfs(i, N, visited, Path);
		// 元に戻す
		visited[i] = false;
	}
	return ans;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<bool>> Path(N, vector<bool>(N)); // 経路があることを示す表

	for (size_t i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Path[a - 1][b - 1] = true;
		Path[b - 1][a - 1] = true;
	}

	vector<bool> visited(N);
	visited[0] = true;

	cout << dfs(0, N, visited, Path) << endl;

	return 0;
}

