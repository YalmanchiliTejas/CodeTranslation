#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000000010;
constexpr ll INF = 1000000000000000010;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	vector<P> p(n);
	rep(i, n) {
		cin >> p[i].first >> p[i].second;
		if (p[i].first > p[i].second) swap(p[i].first, p[i].second);
	}
	sort(all(p));
	int idx = 0, check = 0;
	rep(i, n) if (chmax(check, p[i].second)) idx = i;
	ll mi = p[0].first; ll ma = p[idx].second;
	ll ans = INF;
	ll ma1 = 0; ll mi2 = inf;
	rep(i, n) {
		chmax(ma1, p[i].first);
		chmin(mi2, p[i].second);
	}
	chmin(ans, (ma1 - mi)*(ma - mi2));
	if (idx == 0) {
		cout << ans << '\n';
		return 0;
	}
	ll x = p[0].second; ll y = p[idx].first;
	if (x > y) swap(x, y);
	vector<P> a;
	rep(i, n) {
		if (i == 0 || i == idx) continue;
		P ap;
		if (p[i].second < p[i].first) swap(p[i].first, p[i].second);
		if (p[i].first < x&&p[i].second < x) {
			ap.first = x - p[i].second;
			ap.second = inf;
		}
		else if (p[i].first > y&&p[i].second > y) {
			ap.second = p[i].first - y;
			ap.first = inf;
		}
		else {
			ap.first = max(x - p[i].first, 0LL);
			ap.second = max(p[i].second - y, 0LL);
		}
		a.pb(ap);
	}
	sort(all(a));
	vector<ll> af(n - 2), as(n - 2);
	rep(i, n - 2) {
		if (i == 0) af[i] = a[i].first;
		else af[i] = max(af[i - 1], a[i].first);
	}
	for (int i = n - 3; i >= 0; i--) {
		if (i == n - 3) as[i] = a[i].second;
		else as[i] = max(as[i + 1], a[i].second);
	}
	ll v = inf;
	rep(i, n - 3) chmin(v, af[i] + as[i + 1]);
	if (n > 2) {
		chmin(v, af[n - 3]);
		chmin(v, as[0]);
	}
	v += y - x;
	chmin(ans, v*(ma - mi));
	cout << ans << '\n';
}