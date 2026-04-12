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
const int N = 4e5 + 20;
const int mod = 1e9 + 7;
const int inf = 2e9 + 7;

int n, k;
string s;
ll dp[10010][110];

ll get(string& s) {
	ll ans = 0;
	int cur = 0;
	for (int i = 0; i < sz(s); i++) {
		int z = s[i] - '0';
		for (int j = 1; j <= z; j++) {
			int sum = (cur + j - 1) % k;
			ans = (ans + dp[sz(s) - 1 - i][(k - sum) % k]) % mod;	
		}	
		cur = (cur + z) % k;
	}
	if (cur % k == 0) ans = (ans + 1) % mod;
	re ans;
}

int main() {
	cin >> s >> k;
	dp[0][0] = 1;
	for (int i = 1; i < 10010; i++)
		for (int j = 0; j < k; j++) 
			for (int p = 0; p < 10; p++)
				dp[i][j] = (dp[i][j] + dp[i - 1][(j - p + 10 * k) % k]) % mod;
	cout << (get(s) - 1 + mod) % mod;
}