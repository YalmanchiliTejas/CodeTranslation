#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <numeric>
#include <iomanip>
 
 
int main()
{
	long long n;
 
	std::cin >> n;
 
	std::cout << n * 800 - (n / 15) * 200 << std::endl;
	return 0;
}