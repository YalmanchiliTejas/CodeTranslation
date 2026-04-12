#include <bits/stdc++.h>
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

int main() {
	i64 n, x; scanf("%lld%lld", &n, &x);
	
	i64 p = 1, b = 0;
	for(int i = 0; i < n; i++) {
		p = 2 * p + 1;
		b = 2 * b + 2;
	}
	i64 ans = 0;
	while(p > 1 and x) {
		p = (p - 1) >> 1;
		b = (b - 2) >> 1;
		if(p + b + 1 < x) {
			ans += p + 1;
			x -= p + b + 2;
		} else {
			x--;
		}
	}
	if(x) ans++;
	printf("%lld\n", ans);
	return 0;
}
