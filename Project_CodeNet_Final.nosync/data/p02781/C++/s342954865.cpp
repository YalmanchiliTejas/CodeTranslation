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

	string S;
	int K;
	cin >> S >> K;
	int N = S.size();
	int dp[N+1][2][K+2];
	rep(i,N+1){
		rep(j,2){
			rep(k,K+1){
				dp[i][j][k] = 0;
			}
		}
	}
	dp[0][0][0] = 1;
	rep(i,N){
		int n = S[i] - '0';
		rep(smaller, 2){
			rep(j,K+1){
				rep(x,(smaller ? 10 : n+1)){
					if(x == 0){
						dp[i+1][smaller || x<n][j] += dp[i][smaller][j];
					}
					else{
						dp[i+1][smaller || x<n][j+1] += dp[i][smaller][j];
					}
				}
			}
		}
	}
	cout << dp[N][0][K] + dp[N][1][K] << endl;
	
}