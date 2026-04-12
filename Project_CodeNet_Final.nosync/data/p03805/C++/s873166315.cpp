#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
bool e[8][8];

int ans = 0;
bool visited[8];

void dfs(int n,int node) {

	if (n == N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (e[node][i] && !visited[i]) {
			visited[i] = true;
			dfs(n + 1, i);
			visited[i] = false;
		}
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a][b] = e[b][a] = true;
	}
	
	visited[0] = true;
	dfs(1, 0);

	cout << ans << endl;

	return 0;
}