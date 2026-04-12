#include <iostream>

int n, t, e;

bool res(int lb, int rb, int x) {
	int m = rb / x*x;
	return m >= lb;
}

int main() {
	std::cin >> n >> t >> e;
	int lb = t - e, rb = t + e;
	int x;
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		if (res(lb, rb, x)) {
			std::cout << i + 1 << std::endl;
			goto a;
		}
	}
	std::cout << -1 << std::endl;
a:;
	return 0;
}