#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
	long long A, B, C;
	int X, Y;
	cin >> A >> B >> C >> X >> Y;

	auto cost = 0ull;

	if (A + B > 2 * C)
	{
		auto m = min(X, Y);
		X -= m;
		Y -= m;
		cost += C * 2 * m;
	}
	if (X > 0 && A > 2 * C)
	{
		cost += C * 2 * X;
		Y -= X;
		X = 0;
	}
	if (Y > 0 && B > 2 * C)
	{
		cost += C * 2 * Y;
		X -= Y;
		Y = 0;
	}

	if (X > 0)
	{
		cost += A * X;
	}
	if (Y > 0)
	{
		cost += B * Y;
	}

	cout << cost << endl;

	return 0;
}
