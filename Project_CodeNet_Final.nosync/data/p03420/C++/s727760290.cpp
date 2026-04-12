#include <iostream>

int main() {
	int n, k;
	std::cin >> n >> k;
	if(k == 0) {
		std::cout << (long long) n * n << '\n';
		return 0;
	}
	long long ans = 0;
	for(int i = k + 1; i <= n; i++) {
		ans += (long long) n / i * (i - k) + std::max(n % i - k + 1, 0);
	}
	std::cout << ans << '\n';
}