#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;

	std::cout << (s.find("AC") != std::string::npos ? "Yes" : "No") << std::endl;
}