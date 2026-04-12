#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <math.h>
#include <time.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
int main() {
	int a, b, c, x, y, z;
	cin >> a >> b >> c >> x >> y;
	bool isX = false;
	if (x < y)
		z = x;
	else {
		z = y;
		isX = true;
	}
	int ans = min(2 * c*z, z*a + z*b);
	if (isX)
		ans += min(2 * (x - z)*c, (x - z)*a);
	else
		ans += min(2 * (y - z)*c, (y - z)*b);
	cout << ans << endl;
	return 0;
}