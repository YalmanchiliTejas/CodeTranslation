#include <iostream>

int main()
{
	int r, g, b, nr = 0;
	std::cin >> r >> g >> b;
	nr = r * 100 + g * 10 + b;
	if (nr % 4 == 0)
		std::cout << "YES";
	else
		std::cout << "NO";
}