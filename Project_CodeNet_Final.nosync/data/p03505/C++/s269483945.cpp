#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
using namespace std;

typedef long long ll;

int main() {
	ll k, a, b; cin >> k >> a >> b;
	if (k <= a) {
		cout << 1 << endl;
		return 0;
	}
	if (a - b <= 0) {
		cout << -1 << endl;
		return 0;
	}
	ll ans = 2 * ((k - a) / (a - b));
	if ((k - a) % (a - b) != 0) ans += 2;
	cout << ans + 1 << endl;
	return 0;
}