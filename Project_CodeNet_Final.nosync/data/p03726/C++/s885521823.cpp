#include <iostream>
#include <vector>

using namespace std;

const int N = (int) 2e5;

vector <int> g[N];
int match;
int busy[N];

void dfs(int v, int p = -1) {
	for (int to : g[v]) if (to != p) {
		dfs(to, v);
		if (!busy[to] && !busy[v]) {
			match++;
			busy[v] = busy[to] = true;
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	if (match * 2 != n) {
		cout << "First\n";
	} else {
		cout << "Second\n";
	}
	return 0;
}