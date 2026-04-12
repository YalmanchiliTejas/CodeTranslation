#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main();

void Compare_Func_Display(const int &arg_a, int &arg_b);


int main()
{
	const int MIN_LIMIT = -40;
	const int MAX_LIMIT = 40;
	const int ON_TEMPERATURE = 30;

	std::string buf;
	std::cin >> buf;

	int room_temperature = stoi(buf.c_str());

	if ((MIN_LIMIT > room_temperature) || (MAX_LIMIT < room_temperature))
	{
		return 0;
	}
	Compare_Func_Display(ON_TEMPERATURE, room_temperature);
	return 0;
}

void Compare_Func_Display(const int &arg_a, int &arg_b)
{
	if (arg_a <= arg_b)
	{
		std::cout << "Yes" << std::endl;
		return;
	}
	std::cout << "No" << std::endl;
	return;
}
