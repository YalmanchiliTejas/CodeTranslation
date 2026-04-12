#include <iostream>

using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;

	r *= 100; g *= 10;

	cout << (((r + g + b) % 4 == 0) ? "YES" : "NO") << endl;

}
