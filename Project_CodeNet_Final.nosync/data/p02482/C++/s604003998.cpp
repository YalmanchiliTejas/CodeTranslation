#include <iostream>

auto to_relation(int a, int b) -> std::string {
	if (a == b) return "a == b";
	else if (a < b) return "a < b";
	else if (a > b) return "a > b";
	else return "";
}

auto main() -> int {
	int a, b;
	std::cin >> a >> b;
	std::cout << to_relation(a, b) << std::endl;
}