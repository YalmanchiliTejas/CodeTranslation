#include <bits/stdc++.h>
using namespace std;

long long dp[3010][3010], l[3010];

long long solve(int i, int j, int v){
	
	if(i > j) return 0;
	
	if(dp[i][j] == 3000000000000) {
		if(v) dp[i][j] = max(solve(i + 1, j, !v) + (v ? 1 : -1) * l[i], solve(i, j - 1, !v) + (v ? 1 : -1) * l[j]);
		else dp[i][j] = min(solve(i + 1, j, !v) + (v ? 1 : -1) * l[i], solve(i, j - 1, !v) + (v ? 1 : -1) * l[j]);
	}
	
	return dp[i][j];
}

int main(){
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) scanf(" %lld", &l[i]);
	
	for(int i = 0; i < n + 1; i++) for(int j = 0; j < n + 1; j++) dp[i][j] = 3000000000000;
	
	printf("%lld\n", solve(0, n - 1, 1));
	return 0;
}
