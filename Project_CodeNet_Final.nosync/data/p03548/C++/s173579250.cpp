#include <iostream>
using namespace std;

int main() {
	int x, y, z, ans = 0;
	cin >> x >> y >> z;

	if (x > z && (x-z) >= (y+z)) {
		ans += (x - z) / (y + z);
	}

	cout << ans << endl;
}