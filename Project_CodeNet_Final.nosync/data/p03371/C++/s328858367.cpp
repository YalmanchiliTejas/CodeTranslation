#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<cstdio>

using namespace std;

int main() {
	int a, b, c, x, y, m;
	cin >> a >> b >> c >> x >> y;

	m = x>y ? (x-y)*a + 2*y*c : (y-x)*b + 2*x*c;
	if (m > x*a + y*b) m = x*a + y*b;
	if (m > 2*max(x, y)*c) m = 2 * max(x, y)*c;

	cout << m;
	char v;
	cin >> v;
	return 0;
}