#include <bits/stdc++.h>

int n, k;
int main()
{
	std::cin >> n >> k;

	if (k == 0) {
		std::cout << static_cast<long long>(n) * static_cast<long long>(n) << std::endl;
		return  0;
	}

	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (i > k) {
			auto p = n / i;
			auto r = n % i;
			ans += p * std::max(0, i - k) + std::max(0, r - k + 1);
		}
	}

	std::cout << ans << std::endl;
	return 0;
}
