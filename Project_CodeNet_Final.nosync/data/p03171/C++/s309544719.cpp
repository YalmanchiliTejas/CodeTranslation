// " --- IN THE NAME OF ALLAH --- " // ;)
// ------------sphr_agz------------ // ;)
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long double ld;
typedef long long int lli;
typedef pair <lli, lli> pii;
#define pb push_back
#define recout(x) return cout << (x), 0
#define f first
#define s second
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define stp(x) cout << setprecision(x) << fixed
#define mk make_pair
#define all(x) x.begin(), x.end()
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
const lli N = 3e3 + 10, N2 = 2e5, delta = 46639, mod = 1e9 + 7, oo = 1e18, LOG = 20, SQ = 300;
const ld PI = 3.141592653589793;

lli dp[N][N], a[N];

int32_t main() {
	fast;
	lli n;
	cin >> n;
	for (lli i = 0; i < n; i++) {
		cin >> a[i];
		dp[i][1] = a[i];
	}
	for (lli j = 2; j <= n; j++)
		for (lli i = 0; i + j <= n; i++)
			dp[i][j] = max (a[i] - dp[i + 1][j - 1], a[i + j - 1] - dp[i][j - 1]);
	cout << dp[0][n] << '\n';
	return 0;
}
