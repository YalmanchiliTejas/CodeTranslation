#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n[5010];
int dp[5010][5010];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	std::ifstream in("in");
	std::cin.rdbuf(in.rdbuf());
#endif

	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> n[i];
	};
	sort(n, n + N);

	memset(dp, -1, sizeof dp);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < i; j++){
			dp[i][j] = 2;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < i; j++){
			if(dp[i][j] == -1) continue;
			int pre = n[j];
			int d = n[i] - pre;
			int idx = lower_bound(n, n + N, n[i] + d) - n;
			if(idx < N && n[i] + d == n[idx]){
				dp[idx][i] = max(dp[idx][i], dp[i][j] + 1);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
}

