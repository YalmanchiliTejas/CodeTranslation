#include <iostream>

char c;

int main()
{
	std::cin >> c;
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		std::cout << "vowel\n";
	else
		std::cout << "consonant\n";
}