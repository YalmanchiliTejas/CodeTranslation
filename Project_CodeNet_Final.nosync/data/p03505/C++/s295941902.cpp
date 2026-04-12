#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9 + 7, MOD = 1e9 + 7;
const long long LINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
signed main() {
	int k, a, b;
	cin >> k >> a >> b;
	if (k <= a) {
		cout << 1 << endl;
		return 0;
	}
	if (a <= b) {
		cout << -1 << endl;
		return 0;
	}
	k -= a;
	int div = a - b;
	if (k % div) {
		cout << ((k / div) + 1) * 2 + 1 << endl;
	}
	else {
		cout << 2 * (k / div) + 1 << endl;
	}
	return 0;
}