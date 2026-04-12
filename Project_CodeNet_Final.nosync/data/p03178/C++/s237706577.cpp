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
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

ll mod = 1000000007;
int dp[10010][100][2];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	string k;
	int d;
	cin >> k >> d;
	int n = k.size();
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < d; j++) {
			int c = k[i - 1] - '0';
			dp[i][(j + c) % d][0] += dp[i - 1][j][0];
			dp[i][(j + c) % d][0] %= mod;
			for (int k = 0; k < c; k++) {
				dp[i][(j + k) % d][1] += dp[i - 1][j][0];
				dp[i][(j + k) % d][1] %= mod;
			}
			for (int k = 0; k < 10; k++) {
				dp[i][(j + k) % d][1] += dp[i - 1][j][1];
				dp[i][(j + k) % d][1] %= mod;
			}
		}
	}
	cout << (dp[n][0][0] + dp[n][0][1] + mod - 1) % mod << endl;
}