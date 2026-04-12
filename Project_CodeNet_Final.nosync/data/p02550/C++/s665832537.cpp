#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int history[100000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, x, m;
	cin >> n >> x >> m;
	ll a = x, sum = x;
	history[x] = 1;
	ll loop_start, loop_end = -1;
	ll loop_start_value;
	for (int i = 2; i <= n; i++) {
		a = a * a % m;
		/* cout << i << ':' << a << '\n'; */
		if (history[a]) {
			loop_start = history[a];
			loop_end = i;
			loop_start_value = a;
			break;
		} else {
			history[a] = i;
		}
		sum += a;
	}
	if (loop_end == -1) {
		cout << sum << '\n';
		return 0;
	}
	ll ntimes = (n - loop_start + 1) / (loop_end - loop_start);
	ll rest = (n - loop_start + 1) % (loop_end - loop_start);
	/* cout << loop_start << ' ' << loop_end << ' ' << rest << ' ' << ntimes << '\n'; */
	ll partialsum = (loop_start > 1 ? x : 0);
	a = x;
	for (int i = 2; i < loop_start; i++) {
		a = a * a % m;
		partialsum += a;
	}
	/* cout << sum << ' ' << partialsum << ' ' << sum - partialsum << '\n'; */
	ll totalsum = (sum - partialsum) * ntimes + partialsum;
	a = loop_start_value;
	ll anothersum = loop_start_value;
	for (int i = 2; i <= rest; i++) {
		a = a * a % m;
		anothersum += a;
	}
	if (rest) {
		totalsum += anothersum;
	}

	cout << totalsum << '\n';
	return 0;
}
