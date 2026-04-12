#include <iostream>

int main()
{
    int temparture;

    std::cin >> temparture;

	if (temparture < 30)
	{
		std::cout << "No" << std::endl;
	}
	else
	{
		std::cout << "Yes" << std::endl;
	}
}	