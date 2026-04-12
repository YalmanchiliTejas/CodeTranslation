
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
#include <iomanip>
#include <bitset>
#include <cassert>
using namespace std;

typedef long long ll;

ll cnt[53], pat[53];

ll func(int lev, ll res) {
	if (lev <= 0) return 1;
	if (res <= 1) return 0;
	res--;
	ll ret = 0;
	if (res <= cnt[lev - 1]) {
		ret += func(lev - 1, res);
	}
	else if (res == cnt[lev - 1] + 1) {
		ret += pat[lev - 1] + 1;
	}
	else if (res > cnt[lev - 1] + 1) {
		ret += pat[lev - 1] + 1 + func(lev - 1, res - cnt[lev - 1] - 1);
	}
	return ret;
}

int main() {
	ll n, x; cin >> n >> x;
	for (int i = 0; i <= n; i++) cnt[i] = (i == 0 ? 1 : 2 * cnt[i - 1] + 3);
	for (int i = 0; i <= n; i++) pat[i] = (i == 0 ? 1 : 2*pat[i - 1] + 1);
	pat[0] = 1;
	cout << func(n, x) << endl;
	return 0;
}
