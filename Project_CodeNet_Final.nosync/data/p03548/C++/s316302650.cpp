#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int ans = 0;
	x -= z;
	while (x >= y + z) {
		ans++;
		x -= y + z;
	}
	cout << ans << "\n";
	return 0;
}