#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 100000000000000
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int dp[400005];
int seg[1600005];
int d[400005];
int n, h;
void apply(int i, int val) {
	seg[i] += val;
	if (i < n) d[i] += val;
}

void build(int p) {
	while(p > 1) p >>= 1, seg[p] = max(seg[p << 1], seg[p << 1 | 1]) + d[p];
}

void push(int p) {
	for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (d[i] != 0) {
			apply(i << 1ll, d[i]);
			apply(i << 1ll | 1ll, d[i]);
			d[i] = 0;
		}
	}
}

void inc(int l, int r, int val) {
	r += (n + 1);
	l += n;
	int l0 = l, r0 = r;
	for(; l < r; l >>= 1ll, r >>= 1ll) {
		if(l & 1) apply(l++, val);
		if(r & 1) apply(--r, val);
	}
	build(l0);
	build(r0 - 1);
}

int query(int l, int r) {
	r += n + 1ll; l += n;
	push(l); push(r - 1);
	int y = -inf;
	for(; l < r; l >>= 1, r >>= 1) {
		if(l & 1) y = max(y, seg[l++]);
		if(r & 1) y = max(y, seg[--r]);
	}
	return y;
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cin >> n; n++;
	h = sizeof(int) * 8 - __builtin_clz(n);
	int m; cin >> m;
	std::vector<pair<int, int> > l(m);
	std::vector<int> L(m);
	std::vector<int> R(m);
	std::vector<int> a(m);
	std::vector<pair<int, int> > r(m);
	for (int i = 0; i < m; ++i) {
		cin >> l[i].fi >> r[i].fi >> a[i]; r[i].se = l[i].se = i; R[i] = r[i].fi; L[i] = l[i].fi;
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	int j = 0;
	int k = 0;
	for (int i = 1; i < n; ++i) {
		while (j < m && l[j].fi == i) {
			inc(0, i - 1, a[l[j].se]);
			j++;
		}
		dp[i] = query(0, i - 1);
		inc(i, i, dp[i]);
		dp[i] = max(dp[i], dp[i - 1]);
		while (k < m && r[k].fi == i) {
			inc(0, L[r[k].se] - 1, -a[r[k].se]);
			k++;
		}
	}
	cout << dp[n - 1];
}