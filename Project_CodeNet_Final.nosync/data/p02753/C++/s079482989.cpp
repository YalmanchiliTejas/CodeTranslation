#include <iostream>

int main() {
	std::string str; std::cin >> str;
	const auto count = std::count(str.begin(), str.end(), 'A');
	if (count != 0 && count != 3) {
		std::cout << "Yes\n";
	}
	else {
		std::cout << "No\n";
	}
}