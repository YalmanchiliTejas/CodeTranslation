#include <iostream>
#include <cstdint>

using i64 = std::int64_t;

constexpr i64 Mod = 1e9 + 7;

int main() {
	int n;
	std::cin >> n;

	i64 ans = 0;
	i64 acc = 0;
	for (int i = 0; i < n; ++i) {
		i64 a;
		std::cin >> a;

		(ans += (a * acc) % Mod) %= Mod;
		(acc += a) %= Mod;
	}

	std::cout << ans << std::endl;
}