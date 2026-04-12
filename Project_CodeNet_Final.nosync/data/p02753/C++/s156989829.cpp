#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <map>
#include <algorithm>
#include <functional>
#include <queue>

int main()
{
	std::string S, ans = "No";
	std::cin >> S;

	if ((S == "AAA") || (S == "BBB"))
	{
		ans = "No";
	}
	else{
		ans = "Yes";
	}

	std::cout << ans << std::endl;

	return 0;
}
