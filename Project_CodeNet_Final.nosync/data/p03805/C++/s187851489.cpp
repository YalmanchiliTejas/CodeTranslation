#include <iostream>
#include <cstdio>
#include<cmath>
#include<set>


using namespace std;

int ans = 0;
bool g[8][8] = {};
bool visited[8] = {};
int n, m;

void dfs(int count, int now) {
	if (count == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i] && g[now][i]) {
			visited[i] = true;
			dfs(count + 1, i);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a][b] = g[b][a] = true;
	}
	visited[0] = true;
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}