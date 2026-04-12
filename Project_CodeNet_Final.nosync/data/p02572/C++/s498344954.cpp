#include <stdio.h>
int n;
long long p = 1000000007;
long long x, s, a;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		a += p - x * x % p;
		a %= p;
		s += x;
		s %= p;
	}
	a += s * s;
	a %= p;
	printf("%lld\n", a * 500000004 % p);
}