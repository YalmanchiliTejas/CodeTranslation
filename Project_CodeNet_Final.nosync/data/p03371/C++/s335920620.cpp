#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int price = (A * X) + (B * Y);

	int mixX = X * 2 * C;
	int mixY = Y * 2 * C;
	if (X > Y) {
		int mod = (X - Y) * A;
		cout << min(mixX, min(mixY + mod, price));
	}
	else {
		int mod = (Y - X) * B;
		cout << min(mixY, min(mixX + mod, price));
	}

	return 0;
}