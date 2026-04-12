#include <iostream>

using namespace std;

int main() {
	int X, Y, Z;

	cin >> X >> Y >> Z;

	int ans = 1;
	X -= Y + 2 * Z;
	while (X >= Y + Z) {
		ans++;
		X -= Y + Z;
	}

	cout << ans << endl;

	return 0;
}