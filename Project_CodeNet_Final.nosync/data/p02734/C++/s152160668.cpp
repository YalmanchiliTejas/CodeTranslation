#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define PI 3.141592653589793238
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;
typedef complex<double> com;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

ll mod = 998244353;
int dp[3010][3010];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n + 1) dp[i][0] = 1;
	rep(i, n) {
		rep(j, 3010) {
			if (j >= a[i]) {
				dp[i + 1][j] += dp[i][j - a[i]];
				dp[i + 1][j] %= mod;
			}
			dp[i + 1][j] += dp[i][j];
		}
	}
	int ans = 0;
	rep(i, n + 1) {
		ans += dp[i][s];
		ans %= mod;
	}
	cout << ans << endl;
}