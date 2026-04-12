#include<iostream>
using namespace std;

bool graph[8][8];
bool visit[8];
int n, m;
bool all_visit;
int ans = 0;

int dfs(int v) {
	visit[v] = true;
	for (int i = 0; i < n; ++i) {
		if (graph[v][i] == false) {
			continue;
		}
		if (visit[i]==true) {
			continue;
		}
		ans += dfs(i);
		visit[i] = false;
	}
	all_visit = true;
	for (int i = 0; i < n; i++) {
		if (visit[i] == false) {
			all_visit = false;
			break;
		}
	}
	if (all_visit == true) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
	}
	for (int i = 0; i < n; i++) {
		visit[i] = false;
	}
	int t = dfs(0);
	cout << ans << endl;
	return 0;
}