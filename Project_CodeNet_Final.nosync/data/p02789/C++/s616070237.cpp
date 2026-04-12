#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <array>
#include <functional>
#include <algorithm>
#include <numeric>
#include <limits>
#include <string>
#include <stack>

int main()
{
	//std::cout << std::fixed << std::setprecision(15);

	int n, m;
	std::cin >> n >> m;

	if (n == m)
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}

	return 0;
}