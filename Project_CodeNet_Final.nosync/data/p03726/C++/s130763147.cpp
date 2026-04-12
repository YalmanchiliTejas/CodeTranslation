#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n;
vector <int> ad[maxn];
int sz[maxn];

bool dfs(int root, int P) {
	sz[root] = 1;
	bool ret = 0, C = 0;
	for (auto x : ad[root]) {
		if (x != P) {
			ret |= dfs(x, root);
			if (sz[x] % 2 == 1) {
				if (C)
					ret = 1;
				C = 1;
			}
			sz[root] += sz[x];
		}
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
	if (dfs(0, -1) || (n % 2 == 1))
		return cout << "First", 0;
	return cout << "Second", 0;
}