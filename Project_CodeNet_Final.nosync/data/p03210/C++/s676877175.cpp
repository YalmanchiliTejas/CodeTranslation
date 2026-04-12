#include <iostream>

using namespace std;

int main() {
	int X;
	cin >> X;

	bool result = false;
	if(X == 3 || X == 5 || X == 7) {
		result = true;
	}

	cout << (result ? "YES" : "NO") << endl;

	return 0;
}
