#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl
#define show2(a, n, m) rep(i, n) { rep(j, m) {cout << a[i][j] << ' ';} cout << endl;} 
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<long long, long long> pll;
typedef long double ld;

const int INF = 1 << 30;
const long long INFL = 1LL << 60;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

typedef vector<vector<ll>> vvll;

int main() {
//	cout << fixed << setprecision(15);
	int n;
	cin >> n;
	vll a(n);
	rep(i, n) cin >> a[i];

	vector<vvll> dp(n+1, vvll(3, vll(2, -INFL)));
	dp[0][0][0] = dp[0][0][1] = 0;
	rep(i, n) {
		rep(j, 3) {
			dp[i+1][j][0] = dp[i][j][1];
			dp[i+1][j][1] = dp[i][j][0] + a[i];
		}
		rep(j, 2) chmax(dp[i+1][j+1][0], dp[i][j][0]);
	}
	if(n % 2) cout << max(dp[n][1][0], dp[n][2][1]) << endl;
	else cout << max(dp[n][0][0], dp[n][1][1]) << endl;
}
