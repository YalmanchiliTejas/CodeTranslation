#include <iostream>

using namespace std;

#define MAXN 8

bool graph[MAXN][MAXN]; // 頂点の隣接情報
//int path[MAXN]; // 経路

// 始点から終点までの経路を表示
/*void print_path(int n)
{
	for (int i = 0; i < n - 1; i++) {
		cout << path[i] << " ";
	}
	cout << path[n - 1] << endl;
}*/

// 頂点vから深さ優先探索(全頂点数n)
int dfs(int v, int n, bool visited[MAXN])
{
	bool a_visited = true;

	// 全頂点を訪問済みなら1を返す
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) a_visited = false;
	}
	if (a_visited) {
		//print_path(n);
		return (1);
	} else {
		int ans = 0;
		// vに隣接している点iを深さ優先探索
		for (int i = 0; i < n; i++) {
			// vとiは隣接しているか
			if (graph[v][i] == false) continue;
			// iは既に訪問しているか
			if (visited[i] == true) continue;
			// 隣接していて未訪問なら訪問
			visited[i] = true;
			/*path[count] = i + 1;
			count++;*/
			// 深さ優先探索
			ans += dfs(i, n, visited);
			// 未訪問にする
			visited[i] = false;
			//count--;
		}
		return (ans);
	}
}

int main()
{
	int n, m;
	int ans;
	//int count = 1; // 訪問した頂点の個数
	bool visited[MAXN]; // 各頂点の訪問状況
	// 読み込み
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = graph[b - 1][a - 1] = true; // 隣接
	}
	// 始点(1)以外の訪問状況を初期化(全て未訪問)
	for (int i = 1; i < n; i++) {
		visited[i] = false;
	}
	// 始点(1)は訪問済みとする
	visited[0] = true;
	//path[0] = count;
	// 始点1、頂点数nで深さ優先探索
	ans = dfs(0, n, visited);
	cout << ans << endl;

	return (0);
}