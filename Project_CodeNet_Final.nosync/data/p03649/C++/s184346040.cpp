# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
constexpr int MOD = 1000000000 + 7;
constexpr int INF = 2000000000;
using namespace std;

int main() {
	int n;
	cin >> n;
	long long a[51];
	long long maxl = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maxl = max(maxl, a[i]);
	}
	long long ans = 0;
	bool update = true;
	while (update) {
		update = false;
		for (int i = 0; i < n; i++) {
			if (a[i] >= n) {
				update = true;
				long long num = ((a[i] - (n - 1)) + n - 1) / n;
				a[i] -= num*n;
				for (int j = 0; j < n; j++) {
					if (i != j)a[j] += num;
				}
				ans += num;
			}
		}
	}
	cout << ans << endl;
}