#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int N, a, b, deg[100009]; vector<int> g[100009];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b; a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	queue<int> que;
	for (int i = 0; i < N; i++) {
		if (deg[i] == 1) que.push(i);
	}
	int cur = N;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		if (deg[u] != 1) continue;
		for (int i : g[u]) {
			if (deg[i] >= 1) {
				deg[i] = deg[u] = 0;
				for (int j : g[i]) {
					if (deg[j] >= 1) deg[j]--;
					if (deg[j] == 1) que.push(j);
				}
			}
		}
		cur -= 2;
	}
	cout << (cur ? "First" : "Second") << '\n';
	return 0;
}