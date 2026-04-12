#include <bits/stdc++.h>
using namespace std;
int dp[110][5][2];

int main(){
	ios::sync_with_stdio(0);
	cout << setprecision(10) << fixed;
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i){
		int sd = s[i] - '0';
		for (int j = 0; j <= k; ++j){
			for (int less = 0; less < 2; ++less){
				for (int d = 0; d <= (less ? 9 : sd); ++d){
					dp[i + 1][j + (d != 0)][less || (d < sd)] += dp[i][j][less];
				}
			}
		}
	}
	cout << dp[n][k][0] + dp[n][k][1];
	return 0;
}

