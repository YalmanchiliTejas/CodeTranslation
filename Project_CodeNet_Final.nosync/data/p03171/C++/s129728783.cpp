#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long long i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define pq priority_queue
#define bcnt(n) __builtin_popcountll(n)

using ll = long long;  // long longをllだけにした
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using mll = map<long long, long long>;
using pll = pair<long long, long long>;
using sll = set<long long>;
using vpll = vector<pair<long long, long long>>;
using mlv = map<long long, vector<long long>>;

int main() {
	ll n;
	cin >> n;
	vll a(n);
	rep(i, n) cin >> a[i];
	vvll dp(n + 1, vll(n + 1, 0));
	rep(i, n + 1) dp[i][i] = 0;
	rep(i, n) {
		rep(j, n) {
			if(i + 1 + j > n) break;

			dp[j][i + 1 + j] = max(a[i + j] - dp[j][i + j], a[j] - dp[j + 1][i + 1 + j]);
		}
	}
	// dp[i][j]は[i,j)でその時点の先手が得る点数
	// rep(i, n) {
	// 	rep(j, n + 1) { cout << dp[i][j] << " "; }
	// 	cout << endl;
	// }
	cout << dp[0][n] << endl;
}
