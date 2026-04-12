#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <stack>
#include <sstream>
#include <set>
#include <cmath>
#include <functional>
#include <numeric>

using namespace std;

int main(void)
{
	int r, g, b;

	cin >> r >> g >> b;

	if (((r * 100) + (g * 10) + b) % 4 == 0)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}