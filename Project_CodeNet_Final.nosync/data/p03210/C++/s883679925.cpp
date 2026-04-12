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
int main() {
	int n;
	std::cin >> n;
	if (n == 3 || n == 5 || n == 7) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}
	return 0;
}