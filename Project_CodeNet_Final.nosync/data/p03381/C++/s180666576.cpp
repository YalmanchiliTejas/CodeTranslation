#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9 + 7, MOD = 1e9 + 7;
const long long LINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
signed main() {
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	int cmp = a[n / 2];
	for (int i = 0; i < n; i++) {
		if (b[i] < cmp) cout << cmp << endl;
		else cout << a[n / 2 - 1] << endl;
	}
	return 0;
}