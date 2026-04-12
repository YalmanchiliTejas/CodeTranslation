

#include <iostream>
#include <cmath>

int main()
{
	int r, g, b;
	std::cin >> r >> g >> b;
	if ((g * 10 + b) % 4 == 0)
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
	return 0;
}