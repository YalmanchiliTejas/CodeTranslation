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
	int n;
	std::cin >> n;
	int x = 800 * n;
	int y = n / 15 *200;
	std::cout << x - y << std::endl;
}