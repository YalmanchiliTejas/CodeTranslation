#include <iostream>
#include <string>

int main()
{

	std::string str;
	std::cin >> str;

	bool hasA = false;
	bool hasB = false;

	for (auto s : str)
	{
		hasA = hasA || (s == 'A');
		hasB = hasB || (s == 'B');
	}

	std::cout << (hasA && hasB ? "Yes" : "No") << std::endl;

	return 0;
}