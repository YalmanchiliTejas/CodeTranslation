#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 3005; 

long long dp[MAX_N][MAX_N]; 
long long a[MAX_N]; 
long long sum[MAX_N];
int n; 

int main () {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]); 
		sum[i] = sum[i - 1] + a[i]; 
	}

	for (int i = 1; i <= n; i++) {
		dp[i][i] = a[i];
	}

	for (int j = 2; j <= n; j++) {
		for (int i = j - 1; i >= 1; i--) {
			dp[i][j] = sum[j] - sum[i - 1] - min(dp[i + 1][j], dp[i][j - 1]);  
		}
	}

	cout << 2 * dp[1][n] - sum[n]; 
	return 0; 
}