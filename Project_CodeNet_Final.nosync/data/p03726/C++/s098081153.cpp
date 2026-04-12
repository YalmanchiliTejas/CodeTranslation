#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int N = 1e5 + 7;

int ok = 1;

int sz[N];
vector<int> g[N];

void dfs(int cur, int p) {
	sz[cur] = 1;
	int c = 0;
	for (auto t : g[cur]) {
		if (t != p) {
			dfs(t, cur);
			c += (sz[t] & 1);
			sz[cur] += sz[t];
		}
	}
	ok &= (c < 2);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i + 1 < n; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, -1);
	ok &= (sz[0] % 2 == 0);
	if (ok) {
		cout << "Second\n"; 	
	} else {
		cout << "First\n";
	}
}