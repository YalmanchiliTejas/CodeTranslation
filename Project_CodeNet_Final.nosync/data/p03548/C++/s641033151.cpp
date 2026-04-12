#include <iostream>
#include <vector>
#include <algorithm>

#define LL long long int
using namespace std;

int main(void)
{
	int x, y, z;
	int temp;
	int ans = 0;
	cin >> x >> y >> z;
	temp = z + y;
	x = x - z;

	ans = x / temp;

	cout << ans << endl;
	return 0;
}