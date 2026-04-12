#include <iostream>

int main()
{
	int meals;
	std::cin >> meals;
	std::cout << (800 * meals - meals / 15 * 200) << std::endl;

	return 0;
}