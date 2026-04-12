#include <bits/stdc++.h>
using namespace std;

using ld = double;
using ll = long long;
using ull = unsigned long long;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;

const int SZ = 1 << 13;
char buff[SZ], *pos = buff + SZ - 1;
#define getchar() (++ pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos)

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

const int N = 1 << 20;

int n, m;

struct Qry {
	int l, r, a;
} q[N];

vector <int> v;
ll a[N];
vector <pair <int, int> > qq[N];

struct Segt {
	int sz;
	ll add[N], mx[N];
	
	void init() {
		for (sz = 1; sz <= n; sz <<= 1);
		for (int i = 1; i < (sz << 1); ++ i) {
			add[i] = 0;
			mx[i] = -LINF;
		}
	}
	
	void pushdown(int i) {
		if (add[i]) {
			if (i < sz) {
				add[i << 1] += add[i];
				add[i << 1 | 1] += add[i];
			}
			mx[i] += add[i];
			add[i] = 0;
		}
	}
	
	void upd(int a, int b, int i, int l, int r, ll v) {
		pushdown(i);
		if (l <= a && b <= r) {
			add[i] += v;
			pushdown(i);
			return;
		}
		if (r <= a || b <= l) return;
		int md = (a + b) >> 1;
		upd(a, md, i << 1, l, r, v);
		upd(md, b, i << 1 | 1, l, r, v);
		mx[i] = mx[i << 1] > mx[i << 1 | 1] ? mx[i << 1] : mx[i << 1 | 1];
	}
	void upd(int l, int r, ll v) { upd(0, sz, 1, l, r, v); }
	void set(int i, ll v) { upd(0, sz, 1, i, i + 1, v - qry(0, sz, 1, i, i + 1)); }
	
	ll qry(int a, int b, int i, int l, int r) {
		pushdown(i);
		if (l <= a && b <= r) return mx[i];
		if (r <= a || b <= l) return -LINF;
		int md = (a + b) >> 1;
		ll L = qry(a, md, i << 1, l, r);
		ll R = qry(md, b, i << 1 | 1, l, r);
		return L > R ? L : R;
	}
	ll qry(int l, int r) { return qry(0, sz, 1, l, r); }
} dp0, dp1, dp2;

int main() {
	n = read(), m = read();
	for (int i = 0; i < m; ++ i) {
		q[i].l = read(), q[i].r = read(), q[i].a = read();
		v.push_back(q[i].l);
		v.push_back(q[i].r + 1);
	}
	v.push_back(1);
	v.push_back(n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	n = (int) v.size();
//	for (int i = 0; i < n; ++ i) cout << v[i] << " \n"[i + 1 == n];
	for (int i = 0; i < m; ++ i) {
		q[i].l = lower_bound(v.begin(), v.end(), q[i].l) - v.begin();
		q[i].r = lower_bound(v.begin(), v.end(), q[i].r + 1) - v.begin();
		a[q[i].l] += q[i].a;
		a[q[i].r] -= q[i].a;
		qq[q[i].r].push_back(make_pair(q[i].l, q[i].a));
	}
	for (int i = 0; i < n; ++ i) a[i + 1] += a[i];
//	for (int i = 0; i < n; ++ i) cout << a[i] << " \n"[i + 1 == n];
	dp0.init();
	dp1.init();
	dp2.init();
	dp0.set(0, 0);
	dp1.set(0, 0);
	dp2.set(0, 0);
	for (int i = 1; i < n; ++ i) {
		dp0.set(i, dp2.qry(0, i));
		dp1.set(i, dp1.qry(0, i));
		ll LL = dp0.qry(i, i + 1);
		ll RR = dp1.qry(i, i + 1) + a[i - 1];
		dp2.set(i, LL > RR ? LL : RR);
		for (int j = 0; j < (int) qq[i].size(); ++ j)
			dp1.upd(qq[i][j].first + 1, i + 1, qq[i][j].second);
	}
//	for (int i = 0; i < n; ++ i) cout << dp0.qry(i, i + 1) << " \n"[i + 1 == n];
//	for (int i = 0; i < n; ++ i) cout << dp1.qry(i, i + 1) << " \n"[i + 1 == n];
//	for (int i = 0; i < n; ++ i) cout << dp2.qry(i, i + 1) << " \n"[i + 1 == n];
	cout << dp2.qry(0, n);
	return 0;
}
