#include <iostream>
#include <algorithm>

int main()
{
	int a, b, c, x, y;
	std::cin >> a >> b >> c >> x >> y;
	long long all_each = a * x + b * y;
	long long all_half = 2 * c * std::max(x, y);
	int half, single, p;
	if (x < y)
	{
		half = x;
		single = y;
		p = b;
	}
	else
	{
		half = y;
		single = x;
		p = a;
	}
	long long mixed = 2 * c * half + p * (single - half);
	std::cout << std::min(std::min(all_each, all_half), mixed) << '\n';
	return 0;
}
