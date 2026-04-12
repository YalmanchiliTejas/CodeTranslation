#include <iostream>
using namespace std;

int main() {
	int x, y, z, n = 0;
	cin >> x >> y >> z;
	x = x - z;
	while (x >= y + z) {
	    x = x - y - z;
	    n++;
	}
	cout << n;
}
