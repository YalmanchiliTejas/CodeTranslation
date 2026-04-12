//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x)  ((int)x.size ())
#define all(x) (x).begin(), (x).end()
#define re return
#define mp make_pair
#define sqrt(x) sqrt (abs(x))
#define y0 y3451
#define y1 y4562
#define j0 j25624
#define j1 j45624
#define makeunique(x) sort(all(x)), (x).resize (unique(all(x)) - (x).begin())

typedef pair <int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef double D;
typedef long double ld;
typedef unsigned int uint;
typedef vector <string> vs;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;

template <class T> using _tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T sqr (T x) { re x * x; }
template <class T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }
template <class T> int sgn (T x) { re x > 0 ? 1 : (x < 0 ? -1 : 0); }

#define filename ""

const D pi = acos(-1.);
const int N = 3e5 + 20;
const ll inf = 1e18 + 7;

int n, m;
ll t[4 * N], how[4 * N];

void push(int v) {
	if (how[v] == 0) re;
	t[2 * v + 1] += how[v];
	t[2 * v + 2] += how[v];
	how[2 * v + 1] += how[v];
	how[2 * v + 2] += how[v];
	how[v] = 0;
}

void modify(int v, int tl, int tr, int l, int r, ll x) {
	if (tl > r || l > tr) re;
	if (l <= tl && tr <= r) {
		how[v] += x;
		t[v] += x;
		re;
	}
	push(v);
	int c = (tl + tr) >> 1;
	modify(2 * v + 1, tl, c, l, r, x);
	modify(2 * v + 2, c + 1, tr, l, r, x);
	t[v] = max(t[2 * v + 1], t[2 * v + 2]);
}

ll get(int v, int tl, int tr, int l, int r) {
	if (tl > r || l > tr || l > r) re -inf;
	if (l <= tl && tr <= r) re t[v];
	push(v); int c = (tl + tr) >> 1;
	re max(get(2 * v + 1, tl, c, l, r), get(2 * v + 2, c + 1, tr, l, r));
}

int a[N];
ii seg[N];
vi b[N], e[N];
ll dp[N];							 

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int l, r, z;
		scanf("%d%d%d", &l, &r, &z);
		l--; r--;
		a[i] = z; seg[i] = {l, r};
		b[l].pb(i); e[r].pb(i);
	}
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		for (auto x : b[i])
			cur += a[x];
		dp[i] = cur;
		for (auto x : b[i])
			modify(0, 0, n - 1, seg[x].fi, seg[x].se, -a[x]);
		ll ans = get(0, 0, n - 1, 0, i - 1);
		ans = max((ll)0, ans);
		dp[i] = ans + cur;
		modify(0, 0, n - 1, i, i, dp[i]);
		for (auto x : e[i]) 
			modify(0, 0, n - 1, seg[x].fi, seg[x].se, a[x]), cur -= a[x];
	}
	cout << *max_element(dp, dp + n + 1) << endl;
}