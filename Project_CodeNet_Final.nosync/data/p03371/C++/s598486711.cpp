#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <limits>
#include <unordered_map>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;


int main()
{
	int A, B, C, X, Y;
	std::cin >> A >> B >> C >> X >> Y;

	int ans = 0;
	if (A + B > 2 * C)
	{
		int minXY = min(X, Y);
		ans += C * minXY * 2;
		X -= minXY;
		Y -= minXY;
	}
	if (X == 0 && B > 2 * C)
	{
		ans += C * Y * 2;
	}
	else if (Y == 0 && A > 2 * C)
	{
		ans += C * X * 2;
	}
	else
	{
		ans += A * X;
		ans += B * Y;
	}
	std::cout << ans;
}