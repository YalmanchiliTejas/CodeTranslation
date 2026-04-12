#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define ppp pop_back
#define pii pair<int,int>
#define fi first
#define se second

const int N = 2e5 + 5;
const ll inf = 1e18;

vector<pii> open[N], close[N];
ll dp[N], a[N];
ll t[4*N], ch[4*N];
ll good_value = - inf;
int n;

ll merge(ll a, ll b) {
	return max(a, b);
}

void build() {
	for (int i=0; i<4*N; i++) t[i] = ch[i] = 0;
}

void push(int v, int l, int r) {
	if (!ch[v]) return;
	t[v] += ch[v];
	if (l < r) {
		ch[v+v] += ch[v];
		ch[v+v+1] += ch[v];
	}
	ch[v] = 0;
}

void upd(int v, int l, int r, int L, int R, ll x) {
	push(v, l, r);
	if (l > R || L > r) return;
	if (L <= l && r <= R) {
		ch[v] += x;
		push(v, l, r);
		return;
	}
	int mid = (l + r) / 2;
	upd(v+v, l, mid, L, R, x);
	upd(v+v+1, mid+1, r, L, R, x);
	t[v] = merge(t[v+v], t[v+v+1]);
}

void upd(int L, int R, ll x) {
	upd(1, 1, n, L, R, x);
}

ll get(int v, int l, int r, int L, int R) {
	push(v, l, r);
	if (l > R || L > r) return good_value;
	if (L <= l && r <= R) return t[v];
	int mid = (l + r) / 2;
	return merge(get(v+v, l, mid, L, R), get(v+v+1, mid+1, r, L, R));
}

ll get(int L, int R) {
	return get(1, 1, n, L, R);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int m;
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int l, r, a;
		cin >> l >> r >> a;
		open[l].pb({r, a});
		close[r].pb({l, a});
	}
	a[0] = 0;
	for (int i=1; i<=n; i++) {
		a[i] = a[i-1];
		for (pii cur : open[i]) a[i] += cur.se;
		for (pii cur : close[i-1]) a[i] -= cur.se;
	}
	build();
	for (int i=1; i<=n; i++) {
		for (pii cur : open[i]) {
			upd(i, cur.fi, -cur.se);
		}
		dp[i] = max(a[i], a[i] + get(1, i-1));
		upd(i, i, dp[i]);
		for (pii cur : close[i]) {
			upd(cur.fi, i, cur.se);
		}
	}
	ll ans = 0;
	for (int i=1; i<=n; i++) ans = max(ans, dp[i]);
	cout << ans << "\n";
    return 0;
}
