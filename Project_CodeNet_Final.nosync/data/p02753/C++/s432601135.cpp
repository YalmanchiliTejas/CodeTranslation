#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	char* stations = new char[3];
	for (int i = 0; i < 3; i++) {
		std::cin >> *(stations + i);
	}
	if (*(stations + 0) == *(stations + 1) && *(stations + 1) == *(stations + 2)) {
		std::cout << "No";	
	}
	else {
		std::cout << "Yes";
	}
}
