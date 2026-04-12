#include <stdio.h>
long long n, m, k;
long long ans;
long long x, y;
long long p = 1000 * 1000 * 1000 + 7;
long long rui(long long a, long long b) {
	a %= p;
	if (b == 0) return 1;
	if (b == 1)return a % p;
	if (b == 2)return a * a % p;
	if (b % 2) {
		return rui(rui(a, b / 2), 2) * a % p;
	}
	return rui(rui(a, b / 2), 2);
}
long long inv(long long a) {
	a %= p;
	return rui(a, p - 2);
}
int main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	ans = 1;
	for (int i = 0; i < n; i++) {
		x += i * (n - i); x %= p;
	}
	for (int i = 0; i < m; i++) {
		y += i * (m - i); y %= p;
	}
	ans *= (x * m % p * m % p + y * n % p * n % p); ans %= p;
	ans *= 2; ans %= p;
	ans *= inv(n * m - 1); ans %= p;
	ans *= inv(n * m); ans %= p;
	ans *= k; ans %= p;
	ans *= (k - 1); ans %= p;
	ans *= inv(2); ans %= p;
	for (long long i = 0; i < k; i++) {
		ans *= (n * m - i); ans %= p;
		ans *= inv(i + 1); ans %= p;
	}
	printf("%lld\n", ans);
}