#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

int main()
{
	int A, B, C;
	int X, Y;

	cin >> A >> B >> C >> X >> Y;

	long long ans = LLONG_MAX;

	for (int i = 0; i < X + Y; i++) {
		long long sum = i * 2 * C;
		
		if (X - i > 0)
		{
			sum += A * (X - i);
		}

		if (Y - i > 0)
		{
			sum += B * (Y - i);
		}

		if (ans > sum)
		{
			ans = sum;
		}
	}

	cout << ans << endl;

	return 0;
}
