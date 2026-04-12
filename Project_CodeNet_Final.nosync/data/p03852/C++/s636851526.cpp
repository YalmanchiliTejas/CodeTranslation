#include <iostream>
#include<string>

int main() {
	char c;
	std::cin >> c;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
		std::cout << "vowel";
		return 0;
	}
	std::cout << "consonant";
	return 0;
}