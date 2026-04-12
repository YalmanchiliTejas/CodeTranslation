#include <iostream>
#include <iomanip>
#include <cassert>

#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)


void Main()
{
	int X, Y, Z;
	cin >> X >> Y >> Z;

	int c = X / (Y+Z);
	if (c * (Y+Z) + Z > X) --c;

	cout << c << endl;
}

int main()
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	Main();
	return 0;
}