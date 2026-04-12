#include <iostream>
#include <algorithm>

int main()
{
	int a, b, c, x, y;
	std::cin >> a >> b >> c >> x >> y;
	int buy_each = a * x + b * y;
	int buy_half = 2 * c * std::max(x, y);
	int p = x < y ? b : a;
	int buy_mix = 2 * c * std::min(x, y) +  p * std::abs(x - y);
	std::cout << std::min(std::min(buy_each, buy_half), buy_mix) << '\n';
}
