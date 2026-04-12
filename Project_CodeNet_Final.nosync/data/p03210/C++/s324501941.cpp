#include <iostream>

int main()
{
	int A;

	std::cin >> A;

	switch (A) {
		case 3:
		case 5:
		case 7:
			std::cout << "YES" << std::endl;
			break;
		default:
			std::cout << "NO" << std::endl;
	}

	return 0;
}