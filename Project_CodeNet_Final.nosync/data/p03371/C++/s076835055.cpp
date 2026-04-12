#include <iostream>

using namespace std;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int minSumprice = 0;


	for (int c = 0; c <= (X + Y) * 2; c += 2) {
		int aCount = 0;
		int bCount = 0;
		int cCount = 0;
		if (X > c / 2)aCount = X - c / 2;
		if (Y > c / 2)bCount = Y - c / 2;
		cCount = c;
		int sumPrice = cCount * C + aCount * A + bCount * B;
		if (c == 0)minSumprice = sumPrice;
		else if (sumPrice < minSumprice)minSumprice = sumPrice;
		//			cout << sumPrice  << " " << aCount << " " << bCount << " " << cCount << endl;
		//			cout << sumPrice << endl;
	}
	cout << minSumprice << endl;

	return 0;
}