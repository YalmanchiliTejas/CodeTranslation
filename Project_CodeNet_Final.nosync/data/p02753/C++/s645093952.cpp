#include <iostream>

int main()
{
	std::string S;
	std::cin >> S;
	if (S == "AAA" || S == "BBB") {
		std::cout << "No";
	}
	else {
		std::cout << "Yes";
	}
}