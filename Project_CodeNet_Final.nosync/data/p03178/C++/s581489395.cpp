#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int d, l;
char s[100005];
long long dp[100005][105][2];

long long solve(int idx, int sum, bool ok) {
	if (dp[idx][sum][ok] != -1) return dp[idx][sum][ok];
	
	if (idx == l) {
		if (sum == 0) return 1;
		return 0;
	}
	
	int to = s[idx] - '0';
	
	if (ok) to = 9;
	dp[idx][sum][ok] = 0;
	
	for (int i = 0; i <= to; i++) {
		bool new_ok = ok;
		
		if (i != s[idx] - '0') new_ok |= 1;
		
		dp[idx][sum][ok] = (dp[idx][sum][ok] + solve(idx + 1, (sum + i) % d, new_ok)) % MOD;
	}
	
	return dp[idx][sum][ok];
}

int main() {
	scanf("%s", s);
	scanf("%d", &d);
	
	l = strlen(s);
	memset(dp, -1, sizeof(dp));
	
	printf("%lld\n", (solve(0, 0, 0) - 1 + MOD) % MOD);
}
