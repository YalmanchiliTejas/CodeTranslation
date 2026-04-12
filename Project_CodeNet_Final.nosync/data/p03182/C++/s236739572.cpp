// fest
#include <bits/stdc++.h>	

#define pb push_back
#define F first
#define S second
#define y1 dasdasfasfas
#define x1 wqdadfasfasfas
#define All(c) c.begin(), c.end()
#define SZ(A) (int((A).size()))
#define umap unordered_map
#define __ fflush(stdout)
#define FILENAME ""

typedef long long ll;
typedef long double ld;    

using namespace std;

void FREOPEN() {
	#ifdef LOCAL
		freopen(".in", "r", stdin);
		freopen("1.out", "w", stdout);
	#else
		//freopen(FILENAME".in", "r", stdin);
		//freopen(FILENAME".out", "w", stdout);
	#endif
}

inline double Time() {return (clock() * 1.0) / CLOCKS_PER_SEC; }             

const int N = 200500, inf = 1e9 * 2;

const ll MOD = 1e9 + 7ll, INF = 1e18;

const int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
const int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};

ll t[N * 4], ch[N * 4], pref[N], dp[N];

vector<pair<int, int> > open[N], close[N]; 

void push(int v, int l, int r) {
	if (ch[v] == 0) return;
	t[v] += ch[v];
	if (l < r) {
		ch[v + v] += ch[v];
		ch[v + v + 1] += ch[v];
	}
	ch[v] = 0;
}

void upd(int v, int l, int r, int L, int R, ll x) {
	push(v, l, r);
	if (L > R || L > r || l > R) return;
	if (L <= l && R >= r) {
		ch[v] += x;
		push(v, l, r);
		return;
	}
	int mid = (l + r) / 2;
	upd(v + v, l, mid, L, R, x);
	upd(v + v + 1, mid + 1, r, L, R, x);
	t[v] = max(t[v + v], t[v + v + 1]);
}

ll get(int v, int l, int r, int L, int R) {
	push(v, l, r);
	if (L > r || L > r || l > R) return -INF;
	if (L <= l && R >= r) return t[v];
	int mid = (l + r) / 2;
	return max(get(v + v, l, mid, L, R), get(v + v + 1, mid + 1, r, L, R));
}

int main() {
	FREOPEN();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		open[l].pb({r, x});
		close[r].pb({l, x});
		pref[l] += x;
		pref[r + 1] -= x;
	}
	for (int i = 1; i <= n; i++) pref[i] += pref[i - 1];
	
 	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		while (!open[i].empty()) {
			int l = i, r = open[i].back().F, x = open[i].back().S;
			upd(1, 1, n, l, r, -x);
			open[i].pop_back();
		}
		dp[i] = max(pref[i], pref[i] + get(1, 1, n, 1, i - 1));
		ans = max(ans, dp[i]);
		upd(1, 1, n, i, i, dp[i]);
		while (!close[i].empty()) {
			int l = close[i].back().F, r = i, x = close[i].back().S;
			upd(1, 1, n, l, r, x);
			close[i].pop_back();
		}
 	}
 	printf("%lld", ans);
	return 0;
}
