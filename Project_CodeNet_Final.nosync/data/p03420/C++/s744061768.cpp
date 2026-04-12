#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define int long long
signed main() {
	int n, k; cin >> n >> k;
	int ans = 0;
	for (int b = k + 1; b <= n; b++) {
		ans += (n / b * (b - k)) + max((int)0, (n%b) - (k == 0 ? 0 : k - 1));
	}
	cout << ans << endl;
}