#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	long long ans = 0;
	for (int i = k + 1; i <= n; i++) {
		int l = k, r = (i - 1);

		int x = (n - l) / i + 1;
		int y = (n - r) / i + 1;

		int range = (i - 1 - k + 1);

		ans += 1LL * y * range;
		if (x > y) {
			// int d = ((n - l + 1) / i) * i + l;
			// int d = n - ((i - 1) * x + l);
			int d = (n - l) / i * i + l;

			// printf("--> %d %d %d %d %d\n", i, x, y, d, n - d + 1);
			ans += n - d + 1;
		}

	}
	if (k == 0) ans -= n;
	printf("%lld\n", ans);
	return 0;
}