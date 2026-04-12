#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main() {
	int n;
	scanf("%d", &n);
	long long a[n];
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	
	long long sums[n];
	sums[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sums[i] = sums[i + 1] + a[i];
		sums[i] %= MOD;
	}
	
	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		sums[i] -= a[i];
		if (sums[i] < 0) {
			sums[i] += MOD;
		}
		ans += (a[i] * sums[i]) % MOD;
		ans %= MOD;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}