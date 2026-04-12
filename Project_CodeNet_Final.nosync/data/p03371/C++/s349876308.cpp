#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const int INF = (1 << 30) - 1;
const ll INF64 = ((ll)1 << 62) - 1;
const double PI = 3.1415926535897932384626433832795;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int minAbCost = min(a + b, 2 * c);

	if (x == y) {
		cout << minAbCost * x;
		return 0;
	}

	int ans = minAbCost * min(x, y);
	if (x > y) {
		int add = a < 2*c ? (x - y) * a : (x - y) * 2*c;
		cout << ans + add << endl;
	} else {
		int add = b < 2 * c ? (y - x) * b : (y - x) * 2 * c;
		cout << ans + add << endl;
	}
	return 0;
}
