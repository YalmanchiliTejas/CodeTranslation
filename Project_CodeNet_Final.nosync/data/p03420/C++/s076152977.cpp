#include<bits/stdc++.h>
using lint = long long;
int main() {
	lint n, k;
	scanf("%lld%lld", &n, &k);
	lint ans = 0;
	for (lint b = k + 1; b <= n; b++) {
		for (lint pa = 0; pa*b <= n; pa++) {
			lint a = pa*b;
			lint q = std::min(n, a + b - 1) - (a + k)+1;
			if (q > 0)ans += q;
		}
	}
	if (k == 0)ans -= n;
	printf("%lld", ans);
}