//HovalHaq!
#include <bits/stdc++.h>
using namespace std;
const int Mx = 1 << 17;
vector<int> N[Mx];

bool DFS(int v, int p = -1) {
	int c = 0;
	for(int u : N[v])
		if(u != p)
			c += DFS(u, v);
	if(c == 0) return 1;
	if(c == 1) return 0;
	cout << "First";
	exit(0);
}

int main() {
	int n; cin >> n;
	int m = 0;
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		N[v].push_back(u);
		N[u].push_back(v);
		if(N[v].size() > N[m].size()) m = v;
		if(N[u].size() > N[m].size()) m = u;
	}
	cout << (DFS(m) ? "First" : "Second");
}