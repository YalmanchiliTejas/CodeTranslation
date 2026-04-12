#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> s(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	// a > 0
	// b > 0
	// c = a - b: b = a - c > 0
	// a + kc = n - 1

	long long ans = 0;
	int c = 1;
	while (c < n) {

		long long sum = 0;
		int k = 0;
		set<int> s_pos;

		// printf("c %d\n", c);
		while (1) {
			int kc = k * c;
			int a = n - 1 - kc;
			if (a <= c) {
				break;
			}
			if (kc == a || s_pos.count(kc) > 0 || s_pos.count(a) > 0) {
				break;
			}
			s_pos.insert(kc);
			s_pos.insert(a);

			// printf("  %d %d\n", kc, a);
			sum += s[kc];
			sum += s[a];
			ans = max(ans, sum);
			k++;
		}
		c++;
	}

	cout << ans << endl;
	return 0;
}
