// #pragma GCC optimize("Ofast,O3,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <complex>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define endl '\n'
#define hoise cerr<<"hoise - "<<__LINE__<<"\n"
#define tham getchar()
#define set0(ar) memset(ar, 0, sizeof ar)
#define setinf(ar) memset(ar, 126, sizeof ar)
#define vsort(v) sort(v.begin(), v.end())
#define all(x) (x).begin(), (x).end()
#define FASTIO ios::sync_with_stdio(false);cin.tie(nullptr)

using ll = long long;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using vi = vector <int>;
using vl = vector <ll>;
using vpii = vector < pii >;
using vpll = vector < pll >;

const int LOG = 20;
const int N = (int)2e5+6;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const double EPS = 1e-6;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int knight_x[8] = {2, 1, -1, -2, -2, -1, 2, 1}, knight_y[8] = {1, 2, 2, 1, -1, -2, -1, -2};

#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << " ";
    err(++it, args...);
    cout << endl;
}

int flipBit (int mask, int k) { return mask = mask ^ (1 << k); }
bool checkBit (int mask, int k) { return (mask >> k) & 1; }
int setBit (int mask, int k) { return mask = mask | (1 << k); }
int resetBit (int mask, int k) { if (checkBit (mask, k)) { mask = flipBit (mask, k); } return mask; }

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a * b) % MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a + b) % MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

template <typename T> using orderedSet = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using orderedSet1 = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool equalTo ( double a, double b ) { if ( fabs ( a - b ) <= EPS ) return true;	else return false; }
bool notEqual ( double a, double b ){ if ( fabs ( a - b ) > EPS ) return true;	else return false; }
bool lessThan ( double a, double b ){ if ( a + EPS < b ) return true;	else return false; }
bool lessThanEqual ( double a, double b ){ if ( a < b + EPS ) return true;	else return false;}
bool greaterThan ( double a, double b ){ if ( a > b + EPS ) return true;	else return false;}
bool greaterThanEqual ( double a, double b ){ if ( a + EPS > b ) return true;	else return false;}

int kase;

/*--------------------------------------------------------------------------------------------------------------------------*/

void solution () {
	int n;
	cin >> n;
	vl a (n + 1);
	vector <vector <ll> > dp (n + 2, vector <ll> (n + 2, 0LL));
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int sz = 1; sz <= n; ++sz) {
		for (int i = 1; i <= n - sz + 1; ++i) {
			int j = i + sz - 1;
			dp[i][j] = max (a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
		}
	}
	cout << dp[1][n] << endl;
}

int main() {
	FASTIO;
	// freopen ("out.txt", "w", stdout);
	int tc;
	// cin >> tc;
	tc = 1;
	
	while (tc--) {
		solution ();
	}
	
    return 0;
}

/*
 * check corner cases
 * be careful before submitting in Lightoj, SPOJ, UVA
*/
