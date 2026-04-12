#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const ld EPS = 1e-6;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const char nl = '\n';

template <typename T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <typename T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <class T> void ckmin(T& a, T b) { a = min(a, b); }
template <class T> void ckmax(T& a, T b) { a = max(a, b); }

// (Integer/Long).bitCount(x)
int pct(int x) { return __builtin_popcount(x); }
int pct(ll x) { return __builtin_popcountll(x); }

void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) { cerr << h; if (sizeof...(t)) cerr << ", "; DBG(t...); }

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string s = "") {
	unsyncIO();
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

// Binary Exponentiation
ll pow(ll b, ll e, ll m = 0LL, ll ans = 1LL) { while (e) { if (e & 1LL) { ans *= b; if (m) ans %= m; } b *= b, e >>= 1LL; if (m) b %= m; } return ans; }



void solve(int tcn) {
	int x; cin >> x;
	cout << (x >= 30 ? "Yes" : "No") << nl;
}

int main() {
    setIO();

    int t = 1; //cin >> t;
	for (int i = 1; i <= t; ++i) {
		//cout << "Case #" << i << ": ";
		solve(i);
	}
	return 0;
}