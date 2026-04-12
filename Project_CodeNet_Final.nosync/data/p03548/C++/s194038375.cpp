#include <iostream>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int end = x % (z + y);
	int ans = x / (z + y);
	if (end < z)
		ans--;
	cout << ans << endl;
	return 0;
}