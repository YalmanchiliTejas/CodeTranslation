/*
--------------              |   /
      |                     |  /
      |                     | /
      |             *       |/          |    |         ------            *
      |                     |           |    |        /      \
      |             |       |\          |    |       |       |\          |
   \  |             |       | \         |    |       |       | \         |
    \ |             |       |  \        |    |        \     /   \        |
     V              |       |   \        \__/|         -----     \       |
*/
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
#define mem(i,j) memset(i,j,sizeof (i));
#define F first
#define S second
#define lowbit(x) ((x)&(-(x)))
#define siz(v) (int)(v).size()
typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
/*-----------------------------------------------------------------------------------------------------*/

signed main() {
	EmiliaMyWife

	int n;
	cin >> n;
	vector<ll> arr(n+1), sum(n+1);
	vector<vector<ll>> dp(n+2, vector<ll>(n+2));
	for(int i = 1; i <= n; i++)
		cin >> arr[i], sum[i] = arr[i]+sum[i-1];
	for(int j = 1; j <= n; j++)
		for(int i = j; i; i--){
			if(i == j)
				dp[i][j] = arr[i];
			else
				dp[i][j] = sum[j]-sum[i-1]-min(dp[i+1][j], dp[i][j-1]);
		}
	cout << 2*dp[1][n]-sum[n] << '\n';
	

	return 0;
}
