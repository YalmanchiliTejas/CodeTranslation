#include <iostream>
#include<string>

int main() {
	int sheet, ans;
	std::cin >> sheet >> ans;
	if (sheet == ans) {
		std::cout << "Yes";
		return 0;
	}
	std::cout << "No";
}