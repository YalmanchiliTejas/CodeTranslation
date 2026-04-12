#include <bits/stdc++.h>
using namespace std;
int main() {
	
	int n, k; scanf("%d%d", &n, &k);
	long long ans = 0;
	for (int i = k + 1; i <= n; ++i) {
		int t = n / i;
		ans += t * (i - k);
		t = t * i;
		ans += max(0, n - t - max(0, k - 1));
	}
	printf("%lld", ans);
	return 0;

}