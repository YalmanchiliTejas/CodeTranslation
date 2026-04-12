#include<cstdio>
long long max(long long a, long long b) {
	return a > b ? a : b;
}
int main() {
	long long n, k, a, b, sum = 0;
	scanf("%lld%lld", &n, &k);
	if (k == 0) {
		printf("%lld", n*n);
		return 0;
	}
	for (b = k + 1; b <= n; b++) {
		sum += (b - k)*(n / b) + max(0, n%b - k + 1);
	}
	printf("%lld", sum);
	return 0;
}