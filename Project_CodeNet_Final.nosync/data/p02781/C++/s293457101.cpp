#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	std::string s;
	std::cin >> s;
	for (auto &i : s) i -= '0';
	int n = s.size();
	int num = ri();
	int dp[n + 1][num + 1][2];
	memset(dp, 0, sizeof(dp));
	dp[0][0][1] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= num; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l <= (k ? s[i] : 9); l++) {
					if (l && j == num) continue;
					int &target = dp[i + 1][j + !!l][k && l == s[i]];
					target += dp[i][j][k];
				}
			}
		}
	}
	printf("%d\n", dp[n][num][0] + dp[n][num][1]); 
  	return 0;
}
