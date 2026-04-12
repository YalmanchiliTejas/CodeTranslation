#include <iostream>

int main() {
	int a;
	std::cin >> a;
	switch (a) {
	case 7:
		std::cout << "YES" << std::endl; return 0;
			break;
		case 5:
			std::cout << "YES" << std::endl; return 0;
			break;
		case 3:
			std::cout << "YES" << std::endl; return 0;
			break;
		default:
			std::cout << "NO" << std::endl; return 0;
			break;
	}
}