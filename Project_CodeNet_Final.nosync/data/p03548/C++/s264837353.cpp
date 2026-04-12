#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int x, y, z;
	int ans = 1;
	cin >> x >> y >> z;
	x -= y + 2 * z;
	ans += x / (y + z);
	cout << ans << endl;
	return 0;
}