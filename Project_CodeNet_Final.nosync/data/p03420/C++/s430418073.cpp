#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; i++)

using namespace std;

int main() {

	int n, k;
	scanf("%d%d", &n, &k);

	if (!k) {
		printf("%lld\n", 1ll * n * n);
		return 0;
	}

	long long ans = 0;
	
	For(i, k + 1, n) {
		ans += 1ll * (n / i) * (i - k);
		ans += max(0, n % i - (k - 1));
	}
	printf("%lld\n", ans);

	return 0;
}