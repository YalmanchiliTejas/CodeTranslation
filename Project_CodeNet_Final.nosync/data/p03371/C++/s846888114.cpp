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

	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	C *= 2;

	long long result = 0;
	if (A + B < C)
	{
		result = A * X + B * Y;
	}
	else
	{
		int same_cnt = min(X, Y);
		result = same_cnt * C;

		if (same_cnt < X)
		{
			result += min((X - same_cnt) * A, (X - same_cnt) * C);
		}
		else
		{
			result += min((Y - same_cnt) * B, (Y - same_cnt) * C);
		}
	}

	cout << result;

	return 0;
}
