#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int X;
	cin >> X;

	cout << (X > 1 and X < 9 and X % 2 == 1 ? "YES" : "NO") << endl;

	return 0;
}