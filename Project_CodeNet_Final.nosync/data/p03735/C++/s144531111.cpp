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

typedef long long ll;

const int N = 2e5 + 9;
const int INF = 1e9 + 239;

int a[N];
int b[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	int n;
	cin >> n;
	int mx = -INF;
	int mn = INF;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		mx = max(mx, max(a[i], b[i]));
		mn = min(mn, min(a[i], b[i]));
	}
	ll ans = (ll)INF * INF;
	{
		int min_f = INF;
		int min_s = INF;
		int max_f = -INF;
		int max_s = -INF;
		for (int i = 0; i < n; i++) {
			int v = (a[i] > b[i]);
			if (v) swap(a[i], b[i]);
			// swap(a[i], b[i]);
			min_f = min(min_f, a[i]);
			min_s = min(min_s, b[i]);
			max_f = max(max_f, a[i]);
			max_s = max(max_s, b[i]);
		}
		ans = min(ans, ((ll)max_f - (ll)min_f) * (max_s - min_s));
	}
	{
		vector<int> ind(n);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return a[i] < a[j];
		});
		multiset<int> s;
		int c = INF;
		for (int i = 0; i < n; i++) {
			s.insert(a[i]);
		}
		c = *s.rbegin() - *s.begin();
		for (auto i : ind) {
			s.erase(s.find(a[i]));
			s.insert(b[i]);
			c = min(c, *s.rbegin() - *s.begin());
		}
		ans = min(ans, (ll)c * (mx - mn));
	}
	cout << ans << endl;
}