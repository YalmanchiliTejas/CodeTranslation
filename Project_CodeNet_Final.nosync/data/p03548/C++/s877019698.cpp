#include <iostream>

using namespace std;

int main()
{
	long long x, y, z;
	long long ans = 0;
	cin >> x >> y >> z;
	x -= z;
	y += z;
	ans = x / y;
	cout << ans;
	return 0;
}