#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define int long long
signed main() {
	int n; cin >> n;
	int ans = 10000, sum = 0;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		sum += a;
		ans = min(ans, sum / i);
	}
	cout << ans << endl;
}
