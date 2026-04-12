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

	int N;
	cin >> N;

	if (N >= 30)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	return 0;
}
