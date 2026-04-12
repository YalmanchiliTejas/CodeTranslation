
#include <iostream>

int main()
{
	int benchWidth, personWidth, spaceWidth;
	std::cin >> benchWidth >> personWidth >> spaceWidth;

	std::cout << (benchWidth - spaceWidth) / (spaceWidth + personWidth);

    return 0;
}