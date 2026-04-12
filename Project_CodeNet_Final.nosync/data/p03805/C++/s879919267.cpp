#include <bits/stdc++.h>
using namespace std;

#define INF 2000000000
#define LINF 9000000000000000000

typedef long long ll;
typedef pair<int, int> P;

int n, m;
bool d[8][8];
bool visited[8];

int dfs(int v) {
	bool all = true;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) all = false;
	}
	if (all) return 1;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!d[v][i]) continue;
		if (visited[i]) continue;
		visited[i] = true;
		cnt += dfs(i);
		visited[i] = false;
	}

	return cnt;
}

int main(){
	cin.tie(0);
  ios::sync_with_stdio(false);

	for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) d[i][j] = false;
	for (int i = 0; i < 8; i++) visited[i] = false;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		d[a][b] = d[b][a] = true;
	}

	visited[0] = true;
	int ans = dfs(0);
	cout << ans << endl;

	return 0;
}
