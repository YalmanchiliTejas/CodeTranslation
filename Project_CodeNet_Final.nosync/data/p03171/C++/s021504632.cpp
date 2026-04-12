#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	long long a[n];
	for(int i=0; i<n; i++) {
		scanf("%lld", &a[i]);
	}

	long long dp[n][n];
	for(int i=0; i<n; i++) {
		dp[i][i] = a[i];
	}
	for(int len=2; len<=n; len++) {
		for(int i=0,j=i+len-1; j<n; i++,j++) {
			dp[i][j] = max(a[j]-dp[i][j-1], a[i]-dp[i+1][j]);
		}
	}
	printf("%lld\n", dp[0][n-1]);
    return 0;
}