#include <iostream>

const int MAX = 1e5;

long long a[MAX];
long long b[MAX];

long long f(long long n, long long x) {
	if (n == 0) {
		if (x <= 0) {
			return 0;
		} else {
			return 1;
		}
	} else if (x <= 1 + a[n - 1]) {
		return f(n - 1, x - 1);
	} else {
		return b[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
	}
}

int main() {
	long long n;
	long long x;
	scanf("%lld %lld", &n, &x);
	a[0] = 1;
	b[0] = 1;
	for (long long i = 1; i < n; i++) {
		a[i] = a[i-1] * 2 + 3;
		b[i] = b[i-1] * 2 + 1;
	}
	printf("%lld\n", f(n, x));
	return 0;
}