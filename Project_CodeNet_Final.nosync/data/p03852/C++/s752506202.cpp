#include <iostream>

int main() {
	char c = '\0';

	std::cin >> c;

	switch (c) {
	case 'a':
		std::cout << "vowel";
		break;
	case 'e':
		std::cout << "vowel";
		break;
	case 'i':
		std::cout << "vowel";
		break;
	case 'o':
		std::cout << "vowel";
		break;
	case 'u':
		std::cout << "vowel";
		break;
	default:
		std::cout << "consonant";
		break;
	}

	return 0;
}
