#include <iostream>

int main() {
	long long int a, b;

	std::cin >> a >> b;

	std::cout << (a < b ? "a < b" : a > b ? "a > b" : "a == b");
	std::cout << std::endl;

	return 0;
}