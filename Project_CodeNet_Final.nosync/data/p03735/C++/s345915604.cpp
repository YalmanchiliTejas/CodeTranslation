#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << ", ";
#define endln cerr << "\n";
#define chkpt cerr << "-----\n";

const int maxn = 2e5 + 5;
int n;
int x[maxn];
int y[maxn];

int check(int X, vii& seg) {
	int Y = INF;
	FOR(i, 0, sz(seg)) {
		if (seg[i].se <= X) {
			chkmin(Y, seg[i].se);
		}
		else {
			chkmin(Y, seg[i].fi);
		}
	}
	return max(0, X - Y);
}

long long work1(int lo, int hi) {
	vii seg;
	FOR(i, 0, n) {
		if (x[i] > y[i]) swap(x[i], y[i]);
		seg.pb(mp(x[i], y[i]));
	}
	sort(all(seg));
	int k = check(seg.back().fi, seg);
	int limit = 0;
	FOR(i, 0, n) {
		if (y[i] > seg.back().fi) {
			if (limit++ >= 300) break;
			chkmin(k, check(y[i], seg));
		}
	}
	return (long long) (hi - lo) * k;
}

long long work2(int lo, int hi) {
	int mnx = INF, mxy = 1;
	FOR(i, 0, n) {
		if (x[i] < y[i]) swap(x[i], y[i]);
		chkmin(mnx, x[i]);
		chkmax(mxy, y[i]);
	}
	return (long long) (hi - mnx) * (mxy - lo);
}

void solve() {
	cin >> n;
	int mn = INF, mx = 1;
	FOR(i, 0, n) {
		cin >> x[i] >> y[i];
		chkmin(mn, x[i]);
		chkmin(mn, y[i]);
		chkmax(mx, x[i]);
		chkmax(mx, y[i]);
	}
	cout << min(work1(mn, mx), work2(mn, mx)) << "\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
        JUDGE_ONLINE = 0;
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    if (!JUDGE_ONLINE) {
    	//freopen("out.txt", "w", stdout);
    	//cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}