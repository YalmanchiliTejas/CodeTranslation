#include <iostream>

int main()
{
	int temp = 0;
	std::cin >> temp;

	if (temp >= 30) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
	return 0;
}