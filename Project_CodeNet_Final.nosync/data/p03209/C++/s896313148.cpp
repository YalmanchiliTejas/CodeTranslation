#include<iostream>

int main() {
	long long int x;
	int n;
	std::cin >> n >> x;

	long long int *p = new long long int[n + 2];
	long long int *size = new long long int[n + 2];

	p[0] = 1;
	size[0] = 1;
	for (int i = 0; i < n + 1; i++) {
		p[i + 1] = 2 * p[i] + 1;
		size[i + 1] = 2 * size[i] + 3;
	}

	long long int ans = 0;
	for (int i = n; i >= 0; i--) {
		if (x == 0)break;
		if (x == size[i]) {
			ans += p[i];
			break;
		}
		if (x == 1)break;

		if (x >= size[i - 1] + 2) {
			ans += p[i - 1] + 1;
			x -= size[i - 1] + 2;
		}
		else {
			x--;
		}
	}

	printf("%lld", ans);
}
