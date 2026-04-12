#include <iostream>

std::string to_relation(int a, int b) {
	if (a == b) return "a == b";
	else if (a < b) return "a < b";
	else if (a > b) return "a > b";
	else return "";
}

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << to_relation(a, b) << std::endl;
}