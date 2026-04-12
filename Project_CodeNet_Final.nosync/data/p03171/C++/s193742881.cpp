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

int n;
int a[3010];
int dp[3010][3010];
bool vis[3010][3010];

int solve(int l, int r) {
	if (vis[l][r]) {
		return dp[l][r];
	}
	if (l == r) {
		vis[l][r] = true;
		return 0;
	}
	if (n % 2 == (r - l) % 2) {
		vis[l][r] = true;
		return dp[l][r] = max(solve(l, r - 1) + a[r - 1], solve(l + 1, r) + a[l]);
	}
	else {
		vis[l][r] = true;
		return dp[l][r] = min(solve(l, r - 1) - a[r - 1], solve(l + 1, r) - a[l]);
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	cin >> n;
	rep(i, n) cin >> a[i];
	cout << solve(0, n) << endl;
}