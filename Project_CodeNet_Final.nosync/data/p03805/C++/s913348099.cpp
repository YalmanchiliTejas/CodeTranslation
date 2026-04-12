#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)

using namespace std;

int count_path(const vector<vector<int>>& path, uint32_t state, int n, int k, int p) {
	if (k == n) return 1;

	int ans = 0;
	for (auto next : path[p]) {
		if (state & (1 << next)) continue;

		ans += count_path(path, state + (1 << next), n, k + 1, next);
	}

	return ans;
}

int main()
{
	int n, m; cin >> n >> m;

	int ans = 0;

	try {
		vector<vector<int>> path(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			path[a].push_back(b);
			path[b].push_back(a);
		}

		uint32_t init_state = 1 << 1;
		ans = count_path(path, init_state, n, 1, 1);
	}
	catch (exception&e) {
		cout << e.what() << endl;
	}

	cout << ans << endl;

	return 0;
}