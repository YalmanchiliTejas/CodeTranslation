#include <iostream>


int main() {


	std::cin.tie(nullptr); std::ios::sync_with_stdio(false);
	int Z; std::cin >> Z;

	int x = 800 * Z;

	int y = Z / 15*200;
	std::cout << x - y;


	return 0;


}