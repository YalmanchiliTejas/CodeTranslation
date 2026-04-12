#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <numeric>

int main()
{
	long long a, b, c;

	std::cin >> a >> b >> c;

	a -= c;

	std::cout << a / (b + c) << std::endl;
	
	return 0;
}
