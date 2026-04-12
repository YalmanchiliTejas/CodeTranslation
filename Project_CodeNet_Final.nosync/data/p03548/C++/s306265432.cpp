#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
using namespace std;

int X, Y, Z;

int main() {
	cin >> X >> Y >> Z;
	int R = Z;
	for (int i = 1; i <= 1000000; i++) {
		R += (Z + Y);
		if (R > X) { cout << i - 1 << endl; break; }
	}
	return 0;
}