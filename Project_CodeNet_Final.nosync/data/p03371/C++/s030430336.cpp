#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	long long A, B, C, X, Y; std::cin >> A >> B >> C >> X >> Y;
	long long D = (A * X) + (B * Y);
	long long ans{ D };
	long long all{ 0 };
	long long N = std::min(X, Y);
	for (long long i{ 0 }; i <= N; ++i) {
		all = (A * (X - i)) + (B * (Y - i)) + (C * i * 2);
		if (ans > all) ans = all;
	}
	all = 2 * std::max(X, Y) * C;
	if (ans > all) ans = all;
	std::cout << ans << std::endl;

	return 0;
}