# include <bits/stdc++.h>

using namespace std;
#define _USE_MATH_DEFINES_
#define ll long long
#define ld long double
#define Accepted 0
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define every(x) x.begin(),x.end()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define For(i,x,y)  for (ll i = x; i <= y; i ++) 
#define FOr(i,x,y)  for (ll i = x; i >= y; i --)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// ROAD to...                                                                                                                                                                                                                Red

inline void Input_Output () {
	//freopen(".in", "r", stdin);
   //freopen(".out", "w", stdout);
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 2e5 + 123;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
 
int n, m, k;
vector < pair < int, int > > g[N];
ll dp[N];
ll t[N * 4];
ll add[N * 4];

void push (int v, int tl, int tr) {
	t[v] += add[v];
	if (tl != tr) {
		for (int to : {v << 1, v << 1 | 1})
			add[to] += add[v];
	}
	add[v] = 0;
}

void build (int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = INF * (tl > 0);
		return;
	}

	int tm = (tl + tr) >> 1;
	build (v << 1, tl, tm);
	build (v << 1 | 1, tm + 1, tr);

	t[v] = min(t[v << 1], t[v << 1 | 1]);
}

void upd (int l, int r, ll x, int v = 1, int tl = 0, int tr = n) {
	push(v, tl, tr);
	if (tl > r || l > tr) return;
	if (tl >= l && tr <= r) {
		add[v] += x;
		push(v, tl, tr);
		return;
	}

	int tm = (tl + tr) >> 1;
	upd (l, r, x, v << 1, tl, tm);
	upd (l, r, x, v << 1 | 1, tm + 1, tr);

	t[v] = min(t[v << 1], t[v << 1 | 1]);
	
}

int main () {
   	SpeedForce;
	cin >> n >> m;
	ll all = 0;
	for (int i = 1; i <= m; i ++) {
		int l, r, x;
		cin >> l >> r >> x;
		g[r].pb({l, x});
		all += x;
	}

	build(1, 0, n);

	for (int i = 1; i <= n + 1; i ++) {
		for (auto it : g[i - 1]) {
			upd(0, it.F - 1, it.S);
		}
		dp[i] = t[1];
		upd (i, i, dp[i] - INF);
	}

	cout << all - dp[n+1] << '\n';
	        
   	return Accepted;
}

// B...a