#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define int long long
using namespace std;
const int INF = 2e18;
const int MOD = 1e9 + 7;
const int MB = 60;
const int maxN = 3001;

struct SegmentTree {
	vector<int> lazy, mx;
	int n;
	SegmentTree(int x) {
		n = x;
		lazy.resize(n << 2);
		mx.resize(n << 2);
	}

	int start, end, value;
	void update(int l, int r, int v) {
		start = l;
		end = r + 1;
		value = v;
		updateTree(1, 0, n);
	}

	int get(int v) {
		return mx[v] + lazy[v];
	}

	void push(int v, int vl, int vr) {
		mx[v] += lazy[v];
		lazy[vl] += lazy[v];
		lazy[vr] += lazy[v];
		lazy[v] = 0;
	}

	void updateTree(int v, int l, int r) {
		if (start <= l && r <= end) {
			lazy[v] += value;
			return;
		}

		int m = (l + r) >> 1;
		int vl = v << 1;
		int vr = vl + 1;

		push(v, vl, vr);

		if (start < m) updateTree(vl, l, m);
		if (m < end) updateTree(vr, m, r);

		mx[v] = max(get(vl), get(vr));
	}

	int res;
	int get(int l, int r) {
		start = l;
		end = r + 1;
		res = 0;
		getTree(1, 0, n);
		return res;
	}

	void getTree(int v, int l, int r) {
		if (start <= l && r <= end) {
			res = max(res, get(v));
			return;
		}

		int m = (l + r) >> 1;
		int vl = v << 1;
		int vr = vl + 1;

		push(v, vl, vr);

		if (start < m) getTree(vl, l, m);
		if (m < end) getTree(vr, m, r);

		mx[v] = max(get(vl), get(vr));
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> del(n + 2), add(n + 2);
	vector<int> left(m), right(m), value(m);
	for (int i = 0; i < m; i++) {
		int l, r, v;
		cin >> l >> r >> v;
		left[i] = l;
		right[i] = r;
		value[i] = v;
		add[l].pb(i);
		del[r + 1].pb(i);
	}
	
	vector<int> dp(n + 1);
	int now = 0;
	SegmentTree tree(n + 1);

	for (int i = 1; i <= n; i++) {
		for (int j : add[i]) {
			now += value[j];
		}
		for (int j : del[i]) {
			tree.update(left[j], right[j], value[j]);
			now -= value[j];
		}
		dp[i] = tree.get(0, i - 1) + now;
		tree.update(i, i, dp[i] - now);
	}
	
	cout << *max_element(all(dp));
}

signed main() {
	/*
	freopen("search.in", "r", stdin);
	freopen("search.out", "w", stdout);
	*/
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed;
	cout.precision(12);
	solve();
}
