#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (!n)break;
		int _max = 0, _min = 1001, s, ans = 0, i = 0;
		for (i; i < n; ++i) {
			cin >> s;
			ans += s;
			_max = max(_max, s);
			_min = min(_min, s);

		}
		ans -= _max + _min;
		ans = int(ans / (n - 2));
		cout << ans << endl;
	}
	return 0;
}
