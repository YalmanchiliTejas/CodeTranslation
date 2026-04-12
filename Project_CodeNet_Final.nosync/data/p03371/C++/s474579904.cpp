#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace  std;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int price = 0 , price2=INT_MAX;
	if (A + B > 2 * C) {
		if (X > Y) {
			price += 2 * Y * C;
			price += (X - Y) * A;
			price2 = 2 * X * C;
		}
		else {
			price += 2 * X * C;
			price += (Y - X) * B;
			price2 = 2 * Y * C;
		}
	}
	else {
		price = X * A + Y * B;
	}
	if (price2 < price)price = price2;
	cout << price << endl;
	return 0;
}