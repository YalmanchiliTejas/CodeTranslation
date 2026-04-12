#include <iostream>
#include <cstdio>
using namespace std;
long long n;
long long a[200010];
long long dp[200010];
long long sum[200010];
int main() {
	scanf("%lld", &n);
	for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sum[1] = a[1];
	for (long long i = 3; i <= n; i += 2) {
		sum[i] = sum[i - 2] + a[i];
	}
	for (long long i = 2; i <= n; i++) {
		if (i & 1) {
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		} else {
			dp[i] = max(sum[i - 1], dp[i - 2] + a[i]);
		}
	}
	printf("%lld", dp[n]);
	return 0;
}