#include <iostream>
#include <algorithm>
using namespace std;

constexpr int64_t INF = static_cast<int64_t>(1) << 60;

int main()
{
	int64_t A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int64_t min_price = INF;
	for (int64_t i = 0; i/2 <= max(X, Y); i += 2)
	{
		int64_t price = C * i + A * max(X - i/2, static_cast<int64_t>(0)) + B * max(Y - i/2, static_cast<int64_t>(0));
		min_price = min(min_price, price);
	}

	cout << min_price << endl;

	return 0;
}