#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	
	int ans = a * x + b * y;
	int tmp = c * x * 2;
	if (y > x) tmp += min(b * (y-x), 2 * c * (y-x));
	ans = min(ans, tmp);
	
	tmp = c * y * 2;
	if (x > y) tmp += min(a * (x-y), 2 * c * (x-y));
	ans = min(ans, tmp);
	cout << ans << endl;
}
