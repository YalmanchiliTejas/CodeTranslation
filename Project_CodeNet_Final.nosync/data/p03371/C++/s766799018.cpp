
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <random>
#include <queue>

using namespace std;

int main()
{
	int A, B, C, X, Y;

	cin >> A >> B >> C >> X >> Y;

	int min_xy = min(X, Y);

	int sum = 0;

	if (2 * C < A + B) {
		sum = 2 * C * min_xy;
		sum += max(0, X - min_xy) * min(A, 2 * C);
		sum += max(0, Y - min_xy) * min(B, 2 * C);
	}
	else {
		sum += X * min(A, 2 * C);
		sum += Y * min(B, 2 * C);
	}


	int  ans = sum;
	//printf("%.9f", ans);
	std::cout << ans;

	return 0;
}

