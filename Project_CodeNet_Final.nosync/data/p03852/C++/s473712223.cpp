#include <iostream>
#include <string>

std::string c;

int main()
{
	std::cin >> c;

	bool fl = c == "a" || c == "i" || c == "u" || c == "e" || c == "o";

	std::cout << (fl ? "vowel" : "consonant") << std::endl;

	return 0;
}