#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
	return os << "(" << x.first << "," << x.second << ")";
}
typedef long long ll;
typedef long double ld;
int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> v;
	int mx = 0, mn = 1e9 + 1;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		if (x[i] < y[i]) swap(x[i], y[i]);
		v.push_back({x[i], i});
		v.push_back({y[i], i});
		mx = max(mx, x[i]);
		mx = max(mx, y[i]);
		mn = min(mn, x[i]);
		mn = min(mn, y[i]);
	}
	int dx = *max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end());
	int dy = *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end());
	ll ans = (ll)dx * dy;
	sort(v.begin(), v.end());
	int tot = 0;
	vector<int> cnt(n);
	ll diff = mx - mn;
	int j = 1;
	for (int i = 1; i < v.size(); ++i) {
		while (tot < n && j < v.size()) {
			if (++cnt[v[j].second] == 1) {
				++tot;
			}
			++j;
		}
		assert(j > i);
		if (tot == n) ans = min(ans, diff * (v[j - 1].first - v[i].first));
		if (--cnt[v[i].second] == 0) --tot;
	}
	printf("%lld\n", ans);
}
