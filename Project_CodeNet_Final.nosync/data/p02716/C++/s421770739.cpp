
// Problem : F - Select Half
// Contest : AtCoder - AtCoder Beginner Contest 162
// URL : https://atcoder.jp/contests/abc162/tasks/abc162_f
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;	

#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> para;
const ll inf = 1e18 + 7;
const ll maxN = 2e5 + 5;
const ll MOD = 1e9 + 7;

int n, arr[maxN];
vi poss[maxN];
map<int, ll> dp[maxN][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	RI(i, n) cin >> arr[i];
	if (n % 2 == 0) {
		RI(i, n) {
			if (i % 2 == 1) poss[i] = {i / 2, i / 2 + 1};
			else poss[i] = {i / 2};
		}
	} else {
		RI(i, n) {
			poss[i] = {(i - 1) / 2, (i - 1) / 2 + 1};
		}
	}
	// dp[i][f][k] - i-ty, f znaczy czy biore, k - ile wzialem
	dp[0][0][0] = 0;
	dp[0][1][0] = -inf;
	dp[0][0][1] = dp[0][0][2] = dp[0][1][1] = dp[0][1][2] = -inf;
	RI(i, n) {
		for (auto k: poss[i]) dp[i][0][k] = dp[i][1][k] = -inf;
	}
	RI(i, n) {
		for (auto k: poss[i]) {
			FOR(j, i - 3, i - 1) {
				if (j < 0) continue;
				if (dp[j][0].count(k))
					dp[i][0][k] = max(dp[i][0][k], dp[j][0][k]);
				if (dp[j][1].count(k))
					dp[i][0][k] = max(dp[i][0][k], dp[j][1][k]);
				if (dp[j][0].count(k - 1))
					dp[i][1][k] = max(dp[i][1][k], dp[j][0][k - 1] + arr[i]);
				if (dp[j][1].count(k - 1) && j != i - 1) {
					dp[i][1][k] = max(dp[i][1][k], dp[j][1][k - 1] + arr[i]);
				}
			}
		}
	}
	cout << max(dp[n][0][n / 2], dp[n][1][n / 2]) << endl;
	return 0;
}
 
