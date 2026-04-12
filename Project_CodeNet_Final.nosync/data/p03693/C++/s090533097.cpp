#include <iostream>

int main()
{
	int r, g, b;
	std::cin >> r >> g >> b;

	int n = ( r * 100 + g * 10 + b );
	
	std::cout << ( n % 4 == 0 ? "YES" : "NO" ) << std::endl;
	return 0;
}
