#include <bits/stdc++.h>

int n;
long long a[51];

long long solve() {
	long long k = 0;
	for(int i = 0; i < n; ++i) {
		k += a[i] / n;
		a[i] -= (a[i] / n) * (n + 1);
	}
	for(int i = 0; i < n; ++i)
		a[i] += k;
	return k;
}

bool allc() {
	for(int i = 0; i < n; ++i)
	if(a[i] >= n)
		return false;
	return true;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	long long ans = 0;
	while(!allc())
		ans += solve();
	printf("%lld\n", ans);
	return 0;
}
