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

namespace Fenw {
	int f[N];

	void set(int pos, int val) {
		for (int i = pos; i < N; i = (i | (i + 1))) {
			f[i] = max(f[i], val);
		}
	}

	int get(int r) {
		int ans = 0;
		for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
			ans = max(ans, f[i]);
		}
		return ans;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
	}
	auto sn = a;
	sort(sn.begin(), sn.end());
	sn.resize(unique(sn.begin(), sn.end()) - sn.begin());
	for (auto &t : a) {
		t = lower_bound(sn.begin(), sn.end(), t) - sn.begin();
	}
	reverse(a.begin(), a.end());
	for (auto x : a) {
		Fenw::set(x, Fenw::get(x) + 1);
	}
	int ans = *max_element(Fenw::f, Fenw::f + N);
	cout << ans << endl;

}
