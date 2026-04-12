#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <limits>
#include <limits.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;


int main()
{
	int A, B, C, X, Y;
	std::cin >> A >> B >> C >> X >> Y;

	int maxXY = max(X, Y);
	int min_money = INT_MAX;
	for (int ab = 0; ab <= maxXY*2; ab+=2)
	{
		int a = max(X - ab / 2, 0);
		int b = max(Y - ab / 2, 0);
		int money = A * a + B * b + C * ab;
		min_money = min(min_money, money);
	}

	std::cout << min_money;
}