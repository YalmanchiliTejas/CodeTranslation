#include<iostream>
using namespace std;

int main(void) {
	int x, y, z; cin >> x >> y >> z;
	int ans = 0;
	x -= z;

	for (int i = 0;; i++) {
		if (x - (z + y) >= 0) {
			x -= z + y;
			ans += 1;
		}
		else { break; }
	}

	cout << ans << endl;
	return 0;
}

