#include<algorithm>
#include<array>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<iso646.h>
#include<queue>
#include<stack>
#include<string>
#include<vector>

#define FOR(counter,initial_value,condition) for(int counter = initial_value; counter < condition;counter++)

int main()
{
	int r, g, b;
	std::cin >> r >> g >> b;
	if ((g * 10 + b) % 4 == 0) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;
}