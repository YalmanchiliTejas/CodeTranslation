#include <iostream>
#include <string>

int main()
{
	std::string str;
	std::getline(std::cin, str);
	
	for (int i = 0; i < str.length() - 1; ++i)
	{
		if (str[i] == 'A' && str[i + 1] == 'C')
		{
			std::cout << "Yes";
			return 0;
		}
	}
	
	std::cout << "No";
}