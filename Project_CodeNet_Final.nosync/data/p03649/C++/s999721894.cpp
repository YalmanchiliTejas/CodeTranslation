#include <bits/stdc++.h>

typedef long long ll;
const int N = 54;

int n;
ll a[N];

int main() {
	int i; ll r, ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%lld", a + i);
	for (; ; ) {
		i = std::max_element(a, a + n) - a;
		if (a[i] < n) break;
		ans += r = a[i] / n, a[i] -= r * (n + 1);
		for (i = 0; i < n; ++i) a[i] += r;
	}
	printf("%lld\n", ans);
	return 0;
}