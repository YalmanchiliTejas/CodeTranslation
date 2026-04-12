#include <iostream>

int main()
{
	int N;
	std::cin >> N;

	int x, y;
	x = 800 * N;
	y = 200 * int( N / 15 );

	std::cout << x - y << std::endl;

	return 0;
}
