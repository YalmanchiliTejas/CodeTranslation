#include <iostream>
#include <algorithm>

int main(void) {
	int A, B, C, X, Y;
	int ans;
	std::cin >> A >> B >> C >> X >> Y;

	if (A + B <= 2 * C) {
		ans = A * X + B * Y;
		std::cout << ans << '\n';
		return 0;
	}
	if (X == Y) {
		ans = X * 2 * C;
		std::cout << ans << '\n';
		return 0;
	}
	if (X > Y) {
		ans = std::min(std::abs(X - Y) * A + std::min(X, Y) * 2 * C, X * 2 * C);
		std::cout << ans << '\n';
		return 0;
	}
	// X < Y
	ans = std::min(std::abs(X - Y) * B + std::min(X, Y) * 2 * C, Y * 2 * C);
	std::cout << ans << '\n';
	return 0;
}