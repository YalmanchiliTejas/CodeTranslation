#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> h(n);

	for (int i = 0; i < n; i++)
	{
		cin >> h.at(i);
	}

	int c = 1;
	int m = h.at(0);
	for (int i = 1; i < n; i++)
	{
		if (m <= h.at(i))
		{
			c++;

			m = h.at(i);
		}
	}
	cout << c << endl;
}