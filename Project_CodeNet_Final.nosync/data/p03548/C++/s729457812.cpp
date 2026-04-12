#include <iostream>
using namespace std;
int main(void) {
	int x, y, z;
	cin >> x >> y >> z;
	int width = y + z;
	int count = x / width;
	int ans = width * count + z <= x ? count : count - 1;
	cout << ans << endl;
	return 0;
}