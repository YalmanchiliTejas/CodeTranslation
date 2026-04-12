#include <iostream>
int x, y, z;
int main() {
	std::cin >> x >> y >> z;
	std::cout << (x - (2 * z) + z) / (y + z) << std::endl;
}