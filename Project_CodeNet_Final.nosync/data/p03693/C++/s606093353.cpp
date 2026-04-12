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

	int r, g, b;
	cin >> r >> g >> b;

	int value = r * 100 + g * 10 + b;
	if (value % 4 == 0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}
