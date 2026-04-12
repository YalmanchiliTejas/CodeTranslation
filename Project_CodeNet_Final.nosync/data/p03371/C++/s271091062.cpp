#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int a;
	int b;
	int c;
	int x;
	int y;
	cin >> a >> b >> c >> x >> y;

	int ans = a * x + b * y;
	int ubound = 2 * max(x, y);
	int s;
	int t;
	int u;
	int cand;
	for (u = 0; u <= ubound; u++) {
		s = max((int)ceil(x - (double)u / 2.0), 0);
		t = max((int)ceil(y - (double)u / 2.0), 0);
		cand = s * a + t * b + u * c;
		if (cand < ans) {
			ans = cand;
		} 
	}

	cout << ans << endl;
	return 0;

}
