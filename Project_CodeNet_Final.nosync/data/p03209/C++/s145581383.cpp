#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>

using namespace std;

int n;
long long x, ans;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	cin >> x;

	if (x <= n) {
		cout << 0 << endl;
		return 0;
	}

	vector<long long> f(n+1), p(n+1);

	f[0] = p[0] = 1;
	for (int i = 1; i <= n; ++i) {
		f[i] = (f[i-1]<<1) + 3;
		p[i] = (p[i-1]<<1) + 1;
	}

	x = min(x, f[n]);

	while (x > 0) {
		if (x == f[n] || x == f[n]-1) {
			ans += p[n];
			break;
		}

		if (x <= f[n-1] + 1) {
			--n;
			--x;
		} else if (x == f[n-1] + 2) {
			++ans;

			--n;
			x -= 2;
		} else {
			ans += p[n-1] + 1;

			x -= f[n-1] + 2;
			--n;
		}
	}

	cout << ans << endl;
	return 0;
}
