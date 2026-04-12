#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	b += 100 * r + 10 * g;
	cout << ((b % 4) ? "NO" : "YES") << endl;
	return 0;
}