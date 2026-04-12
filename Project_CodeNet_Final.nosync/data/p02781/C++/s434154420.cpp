#include <deque>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	deque<int> a;
	for (int i = 0; i < n; i++) a.emplace_back(s[i] - '0');
	int dp[n][k + 1][2];
	for (int i = 0; i < n; i++){
		dp[i][0][0] = 1;
		dp[i][0][1] = 0;
		for (int j = 1; j <= k; j++){
			dp[i][j][0] = 0;
			dp[i][j][1] = 0;
		}
	}
	dp[0][1][0] = a[0] - 1;
	dp[0][1][1] = 1;
	for (int i = 1; i < n; i++){
		if (a[i] == 0){
			for (int j = 1; j <= k; j++){
				dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j - 1][0] * 9;
				dp[i][j][1] = dp[i - 1][j][1];
			}
		}else{
			for (int j = 1; j <= k; j++){
				dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j - 1][0] * 9 + dp[i - 1][j - 1][1] * (a[i] - 1);
				dp[i][j][1] = dp[i - 1][j - 1][1];
			}
		}
	}
	printf("%d\n", dp[n - 1][k][0] + dp[n - 1][k][1]);
}