#include <iostream>
#include <string>
int main()
{
	char c;
	std::cin >> c;

	char b[5] = { 'a', 'e', 'i', 'o', 'u' };

	for (int i = 0; i < 5; i++) {
		if (b[i] == c) {
			std::cout << "vowel" << std::endl;
			return 0;
		}
	}
	std::cout << "consonant" << std::endl;
    return 0;
}