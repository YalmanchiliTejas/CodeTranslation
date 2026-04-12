#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;
int main(void)

{
	cin.tie(0);
	ios::sync_with_stdio(false);
	long long A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	long long cost = 0;
	//ABピザを使う場合
	if (A + B > 2 * C)
	{
		if (X > Y)
		{
			cost += C * 2 * Y;
			if (A > 2 * C)
				cost += 2 * C * (X - Y);
			else
				cost += A * (X - Y);
		}
		else
		{
			cost += C * 2 * X;
			if (B > 2 * C)
				cost += 2 * C * (Y - X);
			else
				cost += B * (Y - X);
		}
	}
	else
		cost = A * X + B * Y;
	cout << cost;
	return 0;
}
