#include <iostream>

using namespace std;

int main()
{
	long long x, y, z, ans=0;
	cin >> x;	cin >> y;	cin >> z;

	if (x >= y+2*z) {
		ans++;
		x -= y + 2 * z;
	}
	else {
		cout << ans << endl;
		return 0;
	}

	while (x - z - y >= 0) {
		x = x - z - y;
		ans++;
	}

	cout << ans << endl;

	return 0;
}