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
const int N = 2e5 + 20;
const int inf = 1e9 + 7;

int n, m;
int a[3010];
ll dp[3010][3010][2];
bool vis[3010][3010][2];

ll go(int l, int r, int p) {
	if (l > r) re 0;
	if (vis[l][r][p]) re dp[l][r][p];
	vis[l][r][p] = 1;
	ll ans = 0;
	if (!p) ans = max(a[l] + go(l + 1, r, 1), a[r] + go(l, r - 1, 1));
	else ans = min(go(l + 1, r, 0) - a[l], go(l, r - 1, 0) - a[r]);	
	re dp[l][r][p] = ans;

}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << go(0, n - 1, 0);
}