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

#define int long long

const int INF = 1e18 + 239;

int n;
vector<int> a;
map<pair<int, int>, int> mem;

int solve(int len, int cnt) {
	if (cnt > (len + 1) / 2) return -INF;
	if (len <= 0) return 0;
	if (!mem.count({len, cnt})) {
		// cerr << len << ' ' << cnt << endl;
		int f = a[len - 1] + solve(len - 2, cnt - 1);
		int s = solve(len - 1, cnt);
		mem[{len, cnt}] = max(f, s);
	}
	return mem[{len, cnt}];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	a.resize(n);
	for (auto &t : a) {
		cin >> t;
		// t = rand();
	}
	cout << solve(n, n / 2) << endl;
}
