#include <iostream>
#include <cstdint>
#include <algorithm>

int main() {
	int64_t n, k;
	std::cin >> n >> k;

	if (k == 0) {
		std::cout << n * n << std::endl;
		return 0;
	}

	int64_t ans = 0;
	for (int64_t b = k + 1; b <= n; ++b) {
		ans += n / b * (b - k);
		ans += std::max<int64_t>(0, n - n / b * b - k + 1);
	}

	std::cout << ans << std::endl;
}