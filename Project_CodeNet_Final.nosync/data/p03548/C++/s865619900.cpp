#include <iostream>

int main() {
	int x, y, z;
	std::cin >> x >> y >> z;
	int count = (x - z) / (y + z);
	std::cout << count;
	return 0;
}