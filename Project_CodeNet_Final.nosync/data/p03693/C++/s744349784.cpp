#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	int r, g, b;
	std::cin >> r >> g >> b;

	if ((g * 10 + b) % 4 == 0) {
		std::cout << "YES" << std::endl;
	} else {
		std::cout << "NO" << std::endl;
	}
}
