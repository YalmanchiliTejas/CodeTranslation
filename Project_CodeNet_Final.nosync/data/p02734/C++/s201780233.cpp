#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define rep1(i,n) for(int i=1;i<=(int)n;++i)

int N,S;
int A[3010];
int dp[3010][6010];
const int MOD = 998244353;

signed main()
{
	cin >> N >> S;
	rep1(i, N) cin >> A[i];

	rep(i, N+1) dp[i][0] = 1;

	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= S; ++j) {
			dp[i][j] += dp[i-1][j];
			if (j + A[i] <= S*2) {
				//printf("dp[%lld][%lld] += dp[%lld][%lld]\n", i, j+A[i],i-1,j);
				dp[i][j + A[i]] += dp[i-1][j];
			}
			dp[i][j] %= MOD;
		}
	}
	int ans = 0;

	rep(i, N+1) {
		ans += dp[i][S];
		ans %= MOD;
	}

	//rep(i, N+1) {
	//	rep(j, 2*S+1) {
	//		printf("dp[%lld][%lld] = %lld\n", i,j,dp[i][j]);
	//	}
	//	printf("\n");
	//}

	cout << ans << endl;
}
