#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int n;
int a[200005];
long long sum;
long long ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 0; i < n; i++) {
		sum -= a[i];
		ans += (sum % MOD) * (a[i] % MOD);
		ans %= MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
