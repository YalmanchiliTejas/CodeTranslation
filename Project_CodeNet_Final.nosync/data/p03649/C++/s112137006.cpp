#include <bits/stdc++.h>

const int N = 55;

int n;
long long a[N];

void init() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
}

bool check(long long mid) {
	long long t = 0;
	for (int i = 1; i <= n; i++) {
		t += (a[i] + mid + 1) / (n + 1);
	}
	return t <= mid;
}

void work() {
	long long answer = -1;

	std::sort(a + 1, a + n + 1);

	for (int i = 0; i < n; i++) {
		long long low = 0, high = a[n];
		while (low <= high) {
			long long mid = (low + high) >> 1;
			if (check(mid * n + i)) {
				if (answer == -1 || mid * n + i < answer) {
					answer = mid * n + i;
				}
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
	}
	std::cout << answer << std::endl;
}

int main() {
	init();
	work();

	return 0;
}
