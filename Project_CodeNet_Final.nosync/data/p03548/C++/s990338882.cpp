#include <iostream>

using namespace std;

int main(void) {

	int X, Y, Z;

	cin >> X >> Y >> Z;

	int w = X - Z;
	int result = w / (Y + Z);

	cout << result << endl;

	return 0;
}

