#include <iostream>
using namespace std;

int main()
{
	int x, y, z,ans = 0;

	cin >> x >> y >> z;

	x -= z;

	for (;;) {
		x -= y + z;
		if (x < 0)break;
		ans++;
	}

	cout << ans;

	return 0;
}