#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

int n, m, ans;
vector<vector<int>> adj;
vector<bool> used;

void solve(int step, int x) {
	if (used[x]) return;
	if (step == n - 1) {
		ans++;
	}
	else {
		used[x] = true;
		for (auto p : adj[x]) {
			solve(step + 1, p);
		}

		used[x] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int i, j, k, a, b;
	adj.resize(n + 1);
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	used.assign(n + 1, false);
	ans = 0;
	solve(0, 1);
	cout << ans << "\n";


	return 0;
}

