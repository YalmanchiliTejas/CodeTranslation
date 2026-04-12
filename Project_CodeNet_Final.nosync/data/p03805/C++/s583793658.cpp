#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
vector<int> to[9];
bool visit[9];

void dfs(int from) {
	for (int i = 1; i <= n; ++i) {
		if (visit[i] == false) {
			break;
		}
		if (i == n) {
			ans++;
			return;
		}
	}

	for (int i = 0; i < to[from].size(); ++i) {
		if (visit[to[from][i]] == false) {
			visit[to[from][i]] = true;
			dfs(to[from][i]);
			visit[to[from][i]] = false;
		}
	}
}

int main() {
	int a, b;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		to[a].push_back(b);
		to[b].push_back(a);
	}

	visit[1] = true;
	dfs(1);

	cout << ans << endl;

	return 0;
}