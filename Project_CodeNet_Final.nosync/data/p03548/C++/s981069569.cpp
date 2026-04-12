#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdio>
#include <numeric>
#include <functional>
#include <cstdlib>
#include <regex>
#include <list>
	int main() {
		int a, b, c;
		std::cin >> a >> b >> c;
		std::cout << (a - c) / (b + c) << std::endl;
		return 0;
	}