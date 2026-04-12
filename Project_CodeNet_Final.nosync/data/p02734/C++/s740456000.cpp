#include <stdio.h>
long long p = 998244353;
long long ans;
long long n, s;
long long a[3000];
long long dp[3001];
int main() {
	scanf("%lld%lld", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
	dp[0] = 1;
	for (long long i = 0; i < n; i++) {
		for (long long j = s; j > 0; j--) {
			if (j + a[i] <= s) {
				dp[j + a[i]] += dp[j];
			}
		}
		dp[a[i]] += i + 1;
		for (int i = 0; i <= s; i++)dp[i] %= p;
		ans += dp[s];
		ans %= p;
	}
	printf("%lld\n", ans);
}