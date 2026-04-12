#include <bits/stdc++.h>
#define int long long
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 2e5 + 5;
class SegmentTree {
private:
	int lazy[N << 2], t[N << 2];
	void build() { memset(t, 0, sizeof t), memset(lazy, 0, sizeof lazy); }
	void push(int l, int r, int x) {
		t[x] += lazy[x];
		if (l != r) {
			lazy[x << 1] += lazy[x];
			lazy[x << 1 | 1] += lazy[x];
		}
		lazy[x] = 0;
	}
	void upd(int l, int r, int s, int e, int x, int val) {
		push(l, r, x);
		if (l > r || l > e || r < s) return;
		if (s <= l && r <= e) {
			lazy[x] += val;
			push(l, r, x);
			return;
		}
		int m = (l + r) >> 1;
		upd(l, m, s, e, x << 1, val);
		upd(m + 1, r, s, e, x << 1 | 1, val);
		t[x] = max(t[x << 1], t[x << 1 | 1]);
	}
	int get(int l, int r, int s, int e, int x) {
		push(l, r, x);
		if (l > r || l > e || r < s) return -infll;
		if (s <= l && r <= e) return t[x];
		int m = (l + r) >> 1;
		return max(get(l, m, s, e, x << 1), get(m + 1, r, s, e, x << 1 | 1));
	}
public:
	int n;
	void init(int _n) { n = _n, build(); }
	void upd(int l, int r, int val) { upd(0, n - 1, l, r, 1, val); }
	int get(int l, int r) { return get(0, n - 1, l, r, 1); }
} st;
typedef pair<int, int> ii;
int n, m, dp[N], f[N];
vector<ii> le[N];
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	st.init(n);
	cin >> m;
	fw (i, 0, m) {
		int l, r, c;
		cin >> l >> r >> c;
		l--, r--;
		le[r].pb(ii(l, c));
		st.upd(l, r, c);
	}
	fw (i, 0, n) f[i] = st.get(i, i);
	st.init(n);
	fw (i, 0, n) {
		dp[i] = max(0ll, st.get(0, i - 1));
		dp[i] += f[i];
		st.upd(i, i, dp[i] - f[i]);
		fa (j, le[i]) {
			int cost = j.se, l = j.fi;
			st.upd(l, i, cost);
		}
//		cout << "dp[" << i << "] = " << dp[i] << "\n";
	}
	int ans = 0;
	fw (i, 0, n) ans = max(ans, dp[i]);
	cout << ans;
	return 0;
}