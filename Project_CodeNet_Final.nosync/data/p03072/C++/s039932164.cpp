#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int n, ans = 0, now = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x >= now) ans ++;
		now = max(now, x);
	}
	cout << ans << '\n';
	return 0;
}