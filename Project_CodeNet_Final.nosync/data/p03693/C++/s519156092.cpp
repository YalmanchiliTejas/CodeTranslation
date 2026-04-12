#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


int main(void)
{
	int r, g, b;
	int m;
	cin >> r >> g >> b;

	m = 100 * r + 10 * g + b;

	if (m % 4 == 0) {
		cout << "YES" << endl;

	}
	else {
		cout << "NO" << endl;
	}

	return 0;

}