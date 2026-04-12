#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	scanf("%d", &n);
	int a[n];
	long long dp[n+1][n+1];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		dp[i][i] = a[i];
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i + j >= n) break;
			dp[j][j+i] = max(a[j] - dp[j+1][j+i], a[j+i] - dp[j][j+i-1]);
		}
	}
	printf("%lld\n", dp[0][n-1]);
}