#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

/*
dp[i][j] - maximum score first player can be more than opponent at range from i to j.

option 1: choose the first to remove
dp[i][j] = -dp[i+1][j] + A[i]
option 2: choose the last to remove 
dp[i][j] = -dp[i][j-1] + A[j]
*/
int main() {
	int n;
	scanf("%d", &n);
	vector<int> A(n);
	
	for (int i = 0; i < n; i++) {
	    scanf("%d", &A[i]);
	}
	
	vector<vector<ll>> dp(n, vector<ll>(n));
	
	for (int i = n; i >= 0; i--) {
	    for (int j = i; j < n; j++) {
	        ll choose_first = (i+1 > j ? 0 : -dp[i+1][j]) + A[i];
	        ll choose_last = (j-1 < i ? 0 : -dp[i][j-1]) + A[j];
	        dp[i][j] = max(choose_first, choose_last);
	    }
	}
	
	printf("%lld", dp[0][n-1]);
	return 0;
}