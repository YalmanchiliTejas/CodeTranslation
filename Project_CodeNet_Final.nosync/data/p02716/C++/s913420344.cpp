#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
constexpr int MOD = 1000000007;
constexpr int INF = numeric_limits<int>::max() / 2;
typedef pair<int,int> P;
using Graph = vector<vector<int>>;



signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int A[N];
	rep(i,N) cin >> A[i];
	if(N % 2 == 0){
		int dp[N][2];
		rep(i,N){
			rep(j,2){
				dp[i][j] = -1 * INF;
			}
		}
		rep(i,N){
			if(i == 0){
				dp[i][0] = A[0];
				continue;
			}
			if(i == 1){
				dp[i][0] = A[0];
				dp[i][1] = A[1];
				continue;
			}
			if(i % 2 == 0){
				dp[i][0] = dp[i-1][0] + A[i];
				dp[i][1] = dp[i-1][1];
			}
			else{
				dp[i][0] = dp[i-1][0];
				dp[i][1] = dp[i-1][1] + A[i];
			}

			if(i % 2 == 0){
				dp[i][1] = max(dp[i-1][0], dp[i][1]);
			}


		}
		cout << max(dp[N-1][0], dp[N-1][1]) << endl;
	}
	else{
		int dp[N][3]{};
		rep(i,N){
			rep(j,3){
				dp[i][j] = -1 * INF;
			}
		}

		rep(i,N){
			if(i == 0){
				dp[0][0] = A[0];
				dp[0][1] = 0;
				continue;
			}
			if(i == 1){
				dp[1][0] = A[0];
				dp[1][1] = A[1];
				continue;
			}
			if(i == 2){
				dp[i][2] = A[2];
			}

			if(i % 2 == 0){
				dp[i][0] = max(dp[i][0], dp[i-1][0] + A[i]);
				dp[i][2] = max(dp[i][2], dp[i-1][2] + A[i]);
				dp[i][1] = max(dp[i][1], dp[i-1][1]);
				if(i == N-1) dp[i][0] = dp[i-1][0];
			}
			else{
				dp[i][1] = dp[i-1][1] + A[i];
				dp[i][0] = dp[i-1][0];
				dp[i][2] = dp[i-1][2];
			}
			if(i % 2 == 0){
				dp[i][1] = max(dp[i-1][0], dp[i][1]);
			}
			else{
				dp[i][2] = max(dp[i-1][1], dp[i][2]);
			}

		}
		int ans = max(dp[N-1][0], dp[N-1][1]);
		ans = max(ans, dp[N-1][2]);
		cout << ans << endl;
	}
}
