#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdint>

int main() {
	int n;
	std::cin>>n;
	std::vector<long long> a(n+1,0);
	for (int i = 1; i <= n; ++i) {
		std::cin>>a[i];
	}
	long long dp[n+1][n+1];
	memset(dp, 0 ,sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		dp[i][i] = a[i];
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; i + j - 1 <= n; ++j) {
			dp[j][i+j-1] = std::max(a[j] - dp[j+1][i+j-1], a[i+j-1] - dp[j][i+j-2]);
		}
	}
	printf("%lld\n", dp[1][n]);
	return 0;
}
