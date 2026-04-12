#include <iostream>
#include <string>

int main() {
	std::string a;
	std::cin >> a;

	std::cout << (a == "AAA" || a == "BBB" ? "No" : "Yes") << std::endl;
}