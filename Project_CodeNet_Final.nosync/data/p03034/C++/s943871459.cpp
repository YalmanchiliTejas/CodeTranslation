#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <algorithm>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int a[n] = { 0 };
	for (int i = 0; i < n; i++) {
		int x = ri();
		a[i] += x;
		a[n - 1 - i] += x;
	}
	int64_t res = 0;
	for (int i = 1; i < n; i++) {
		int64_t sum = 0;
		for (int cur = i; cur < n; cur += i) {
			sum += a[cur];
			int forward = n - 1 - cur;
			if (forward <= i) continue;
			int back = forward - i;
			if (back % i == 0 && n - 1 >= forward * 2) continue;
			res = std::max(res, sum);
		}
	}
	printf("%" PRId64 "\n", res);
	return 0;
}
