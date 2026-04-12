#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
template <typename T> using ord_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 123, M = 4e5 + 123;
int n, f[M], m, val[M];
array <int, 2> p[N];

void upd(int x, int y) {
	for (; x <= m; x |= (x + 1))
		f[x] = max(f[x], y);
}

int get(int x) {
	int res = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
		res = max(res, f[x]);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i][0] >> p[i][1];
		if (p[i][0] > p[i][1]) swap(p[i][0], p[i][1]);
	}
	sort(p, p + n);
	int mx = -1;
	for (int i = 0; i < n; i++)
		if (mx == -1 || p[i][1] > p[mx][1])
			mx = i;
	int R = p[0][1], B = p[mx][0];
	for (int i = 1; i < n; i++) {
		if (mx == i) continue;
		B = max(B, p[i][0]);
		R = min(R, p[i][1]);
	}
	ll res = (ll)(B - p[0][0]) * (p[mx][1] - R);
	vector <int> v;
	for (int i = 0; i < n; i++) {
		v.pb(p[i][0]), v.pb(p[i][1]);
	}
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	m = v.size();
	int r = min(p[0][1], p[mx][0]);
	for (int i = 1; i < n; i++) {
		if (i == mx) continue;
		r = min(r, p[i][1]);
	}
	for (int i = 0; i < n; i++) {
		int x = lower_bound(all(v), p[i][0]) - v.begin() + 1;
		int y = lower_bound(all(v), p[i][1]) - v.begin() + 1;
		val[x] = p[i][0], val[y] = p[i][1];
		if (i > 0)
			upd(1, p[i][0]);
		if (i != mx)
			upd(x + 1, p[i][1]);
	}
	for (int i = 1; i <= m && val[i] <= r; i++) {
		int g = get(i);
		if (g == 0) continue;
		res = min(res, (ll)(p[mx][1] - p[0][0]) * (g - val[i]));
	}
	cout << res;
}
