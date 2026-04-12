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

using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> s(n);
	for (auto &t : s) {
		cin >> t;
	}
	auto rs = s;
	reverse(rs.begin(), rs.end());
	for (int i = 0; i < n; i++) {
		s[i] += rs[i]; 
	}
	vector<vector<int>> ps(n, vector<int> (1, 0));
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j += i) {
			ps[i].push_back(ps[i].back() + s[j]);
		}
	}
	int ans = 0;
	auto rlx = [&](int a, int b, int k) {
		int c = a - b;
		if (a % c == 0 && a / c <= k) return;
		k++;
		int cr = ps[c][k];
		ans = max(ans, cr);
	};
	n--;
	for (int k = 1; k <= n; k++) {
		for (int c = 0; c <= n / k; c++) {
			int a = n - k * c;
			int b = a - c;
			if (a > 0 && b >= 0 && a > b && a < n) {
				rlx(a, b, k); 
			}
		}
	}
	cout << ans << endl;
}
