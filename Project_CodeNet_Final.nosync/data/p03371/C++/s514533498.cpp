#include <stdio.h>
int max(long long a, long long b) {
	if (a > b)
		return a;
	else
		return b;
}
int main() {
	long long a, b, c, x, y, min = 1e18, ans;
	scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &x, &y);
	for (long long i = 0; i <= 1e5; i++) {
		ans = i * 2 * c;
		ans += max(x - i, 0) * a;
		ans += max(y - i, 0) * b;
		if (ans < min) min = ans;
	}
	printf("%lld\n", min);
	return 0;
}
