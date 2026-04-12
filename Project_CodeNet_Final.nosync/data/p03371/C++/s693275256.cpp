#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define INF 1000000007
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> P;


int main() {

	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	ll res1 = 0, res2 = 0;

	res1 = min(a + b, 2*c)*min(x, y);
	
	if (x == y) {
		cout << res1 << endl;
		return 0;
	}

	if (x > y) {
		res2 = min(a, 2 * c)*(x - y);
	}
	else {
		res2 = min(b, 2 * c)*(y - x);
	}

	cout << res1 + res2 << endl;

	return 0;

}