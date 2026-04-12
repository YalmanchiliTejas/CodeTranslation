#include <iostream>
#include <vector>
#define Graph vector<vector<int>>
using namespace std;

Graph edge(8, vector<int> (8));

// 現在の頂点, 頂点の数, 訪問済みの真偽
int dfs(int v, int n, bool* visited) {
	bool all_visited = true;
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			all_visited = false;
			break;
		}
	}
	// すべての頂点が訪問済みなら1を返す
	if (all_visited)
		return 1;
  
	int ans = 0;
	for (int i = 0; i < n; i++) {
		// 辺が存在しない、または訪問済みならとばす
		if (edge[v][i] == false)
			continue;
		if (visited[i])
			continue;

		visited[i] = true;
		ans += dfs(i, n, visited);
		// ここで未訪問に戻さないと、1通り目で全ての頂点が訪問済みになり、2回目以降がカウントできなくなる
		visited[i] = false;
	}
  
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		// 頂点a-1, b-1間を繋ぐ辺が存在する
		edge[a - 1][b - 1] = true;
		edge[b - 1][a - 1] = true;
	}
  
	// 全ての頂点を未訪問に設定
	bool visited[8];
	for (int i = 0; i < n; i++)
		visited[i] = false;
  
	visited[0] = true;
	int ans = dfs(0, n, visited);
	cout << ans << endl;
  
	return 0;
}