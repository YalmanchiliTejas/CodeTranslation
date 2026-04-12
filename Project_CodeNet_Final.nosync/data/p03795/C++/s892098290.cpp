#include <iostream>

int main() {
	int meal;
	std::cin >> meal;
	std::cout << (meal * 800) - (meal / 15 * 200) << std::endl;
}