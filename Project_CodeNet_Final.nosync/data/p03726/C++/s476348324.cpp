#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;


bool dp1[N], dp0[N], mark[N];
vector <int> adj[N];

void dfs(int v) {
	mark[v] = true;
	bool b = false;
	int c = 0, cl = 0;
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs(u);
			cl++;
			if (dp0[u]) {
				c++;
			}
			if (dp1[u]) {
				b = true;
			}
		}
	}
	if (c == cl) {
		dp1[v] = true;
	}
	if (c + 1 == cl && b) {
		dp0[v] = true;
	}

}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	if (dp0[1]) {
		cout << "Second";
	}
	else {
		cout << "First";
	}
	return 0;
}