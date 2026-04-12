#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
using ll = long long;

ll A[200][200];

int main() {

	int a,b,c,x,y;

	cin >> a >> b >> c >> x >> y;
	int xymax = max(x, y);
	ll min_cost = (ll) 2 << 60;
	for (int i = 0; i <= xymax; i++) {
		ll cost = max(0, (x - i)) * a + max(0, (y - i)) * b + i * 2 * c;
		/*cout << "current cost: " << cost << endl;
		cout << "\ti = " << i << endl;*/
		min_cost = min(min_cost, cost);
	}
	cout << min_cost << endl;
}