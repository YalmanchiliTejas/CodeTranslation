#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

typedef pair < db, db > pdd;
typedef pair < db, ld > pdl;
typedef pair < ld, db > pld;
typedef pair < ld, ld > ldp;

typedef pair < ll, ll > pll;
typedef pair < int, ll > pil;
typedef pair < ll, int > pli;
typedef pair < int, int > pii;

#define F first
#define S second

#define en end()
#define bg begin()

#define rev reverse
#define mp make_pair
#define pb push_back

#define y1 y1234567890
#define um unordered_map

#define all(x) x.bg, x.en
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)

#define sqr(x) ((x + 0ll) * (x))
#define sqrd(x) ((x + 0.0) * (x))

#define forn(i, n) for (int i = 1; i <= n; i++)

const ll inf = (ll)1e18;
const ll mod = (ll)1e9 + 7;

const db eps = (db)1e-9;
const db pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 200500;

int n, m;
vector < int > open[N];
vector < pil > close[N];
ll ans, t[N << 2], k[N << 2], dp[N];

inline void push(int v) {
	t[v << 1] += k[v];
	k[v << 1] += k[v];
	t[v << 1 | 1] += k[v];
	k[v << 1 | 1] += k[v];
	k[v] = 0;
}

void upd(int v, int l, int r, int pos) {
	if (l == r) {
		t[v] = dp[pos];
		return;
	}
	push(v);
	int mid = (l + r) >> 1;
	if (pos <= mid)
		upd(v << 1, l, mid, pos);
	else
		upd(v << 1 | 1, mid + 1, r, pos);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

void upd(int v, int l, int r, int lx, int rx, ll val) {
	if (rx < l || r < lx)
		return;
	if (lx <= l && r <= rx) {
		t[v] += val;
		k[v] += val;
		return;
	}
	push(v);
	int mid = (l + r) >> 1;
	upd(v << 1, l, mid, lx, rx, val);
	upd(v << 1 | 1, mid + 1, r, lx, rx, val);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}

ll get(int v, int l, int r, int lx, int rx) {
	if (rx < l || r < lx)
		return -inf;
	if (lx <= l && r <= rx)
		return t[v];
	push(v);
	int mid = (l + r) >> 1;
	return max(get(v << 1, l, mid, lx, rx), get(v << 1 | 1, mid + 1, r, lx, rx));
}

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//srand(time(NULL));

	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i++) {
		int l, r;
		ll w;
		scanf("%d %d %lld", &l, &r, &w);
		open[l].pb(w);
		close[r].pb({l, w});
	}

	for (int i = 1; i <= n; i++) {
		for (auto j : open[i])
			upd(1, 0, n, 0, i - 1, j);
		dp[i] = get(1, 0, n, 0, i - 1);
		for (auto j : close[i])
			upd(1, 0, n, 0, j.F - 1, -j.S);
		upd(1, 0, n, i);
		ans = max(ans, dp[i]);
	}

	printf("%lld", ans);

	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
