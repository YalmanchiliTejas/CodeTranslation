#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
using namespace std;

const long long INF = 2e18 + 18;

vector<vector<int> > open, close;
vector<int> l, r;
vector<long long> a;

struct T {
	vector<long long> t;
	vector<long long> add;

	void init(int n) {
		t.resize(4 * n);
		add.resize(4 * n);
	}

	void pull(int v) {
		t[v] = max(t[2 * v + 1], t[2 * v + 2]);
	}

	void push(int v) {
		t[2 * v + 1] += add[v];
		t[2 * v + 2] += add[v];
		add[2 * v + 1] += add[v];
		add[2 * v + 2] += add[v];
		add[v] = 0;
 	}

	void apply(int v, long long val) {
		t[v] += val;
		add[v] += val;
	}

	void build(int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = 0;
			add[v] = 0;
		} else {
			int mid = tl + tr >> 1;
			build(2 * v + 1, tl, mid);
			build(2 * v + 2, mid + 1, tr);
			pull(v);
		}
	}

	void update(int v, int tl, int tr, int l, int r, long long val) {
		if (tl > r or l > tr) return;
		else if (tl >= l and tr <= r) {
			apply(v, val);
		} else {
			push(v);
			int mid = tl + tr >> 1;
			update(2 * v + 1, tl, mid, l, r, val);
			update(2 * v + 2, mid + 1, tr, l, r, val);
			pull(v);
		}
	}

	long long get(int v, int tl, int tr, int l, int r) {
		if (tl > r or l > tr) return -INF;
		else if (tl >= l and tr <= r) return t[v];
		else {
			push(v);
			int mid = tl + tr >> 1;
			long long left = get(2 * v + 1, tl, mid, l, r);
			long long right = get(2 * v + 2, mid + 1, tr, l, r);
			pull(v);
			return max(left, right);
		}
	}
};

void solve() {
	int n, m; cin >> n >> m;
	open.resize(n + 1);
	close.resize(n + 1);
	l.resize(m + 1);
	r.resize(m + 1);
	a.resize(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i] >> a[i];
		open[l[i]].pb(i);
		close[r[i]].pb(i);
	}
	T t;
	t.init(n);
	t.build(0, 0, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < int(open[i].size()); j++) {
			int v = open[i][j];
			t.update(0, 0, n, 0, l[v] - 1, a[v]);
		}
		long long res = t.get(0, 0, n, 0, i - 1);
		t.update(0, 0, n, i, i, res);
		for (int j = 0; j < int(close[i].size()); j++) {
			int v = close[i][j];
			t.update(0, 0, n, 0, l[v] - 1, -a[v]);
		}
	}
	cout << t.get(0, 0, n, 0, n) << endl;
}

int main() {
	solve();
	return 0;
}