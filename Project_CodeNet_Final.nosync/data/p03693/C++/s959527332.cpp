#include <iostream>

using namespace std;

int main() {
	int r, g, b; cin >> r >> g >> b;
	int res = 100 * r + 10 * g + b;

	cout << (res % 4 == 0 ? "YES" : "NO") << endl;
}