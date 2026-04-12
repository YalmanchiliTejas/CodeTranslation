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
	int a;
	std::cin >> a;
	if (a == 3 || a == 5 || a == 7) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}
	return 0;
}