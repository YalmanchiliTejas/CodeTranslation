// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
int cnt[N], a[N], b[N];
int32_t main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> a[j] >> b[j];
		if (a[j] > b[j]) {
			swap(a[j], b[j]);
		}
	}
	int res = 1;
	int mx_all = -1e18, mn_all = 1e18;
	for (int j = 0; j < 2; ++j) {
		for (int i = 0; i < n; ++i) swap(a[i], b[i]);	
		int mx = -1e18, mn = 1e18;
		for (int i = 0; i < n; ++i) mx = max(mx, a[i]), mn = min(a[i], mn);
		res *= mx - mn;
		mx_all = max(mx_all, mx);
		mn_all = min(mn_all, mn);
	}
	int range = 1e18;
	vector<pair<int, int>> sweepline;
	set<pair<int, int>, greater<pair<int, int>>> all;
	for (int j = 0; j < n; ++j) {
		sweepline.pb(mp(a[j], j));
		sweepline.pb(mp(b[j], j));
		all.insert(mp(a[j], j));
	}
	sort(ALL(sweepline));
	for (auto x : sweepline) {
		int id = x.second, pl = x.first;
		auto most = *(all.begin());
		range = min(range, most.first - pl);
		if (cnt[id] == 1) break;
		cnt[id] = 1;
		all.erase(x);
		all.insert(mp(b[id], id));
	}
	cout << min(res, range * (mx_all - mn_all)) << endl;
}

