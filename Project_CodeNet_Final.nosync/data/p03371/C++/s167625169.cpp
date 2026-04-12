#include <iostream>
#define min(a, b) a > b ? b : a
using namespace std;

int main () {
	int share, remain, cost = 0;
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	share = min (x, y);
	if (a + b > 2 * c) cost += share * 2 * c;
	else cost += share * (a + b);
	if (x - share) {
		remain = x - share;
		if (a > 2 * c) cost += 2 * c * remain;
		else cost += a * remain;
	} else {
		remain = y - share;
		if (b > 2 * c) cost += 2 * c * remain;
		else cost += b * remain;
	}
	cout << cost << "\n";
	return 0;
}