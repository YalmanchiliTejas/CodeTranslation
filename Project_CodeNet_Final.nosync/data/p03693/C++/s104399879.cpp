#include <iostream>
using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	int num = 100 * r + 10 * g + b;
	cout << (num % 4 ? "NO" : "YES") << endl;
	return 0;
}