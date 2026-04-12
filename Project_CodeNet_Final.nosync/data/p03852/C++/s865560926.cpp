#include <iostream>
#include <string>

int main()
{
	std::string c;
	std::cin >> c;

	if (c[0] == 'a') {
		std::cout << "vowel" << std::endl;
	}
	else if (c[0] == 'i') {
		std::cout << "vowel" << std::endl;
	}
	else if (c[0] == 'u') {
		std::cout << "vowel" << std::endl;
	}
	else if (c[0] == 'e') {
		std::cout << "vowel" << std::endl;
	}
	else if (c[0] == 'o') {
		std::cout << "vowel" << std::endl;
	}
	else {
		std::cout << "consonant" << std::endl;
	}

	return 0;
}