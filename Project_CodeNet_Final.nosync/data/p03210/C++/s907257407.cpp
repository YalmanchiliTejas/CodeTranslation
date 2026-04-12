#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <limits>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int X;
	cin >> X;

	if (X == 3 || X == 5 || X == 7)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}
