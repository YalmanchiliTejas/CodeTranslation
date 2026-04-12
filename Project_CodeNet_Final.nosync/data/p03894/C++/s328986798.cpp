#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	int cur = 0;
	vector<bool> memo(n, false);
	memo[1] = true;
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		swap(memo[a], memo[b]);
		if (cur == a) cur = b;
		else if (cur == b) cur = a;
		if (cur > 0) memo[cur - 1] = true;
		if (cur < n - 1) memo[cur + 1] = true;
	}
	memo[cur] = true;
	int ans = 0;
	for (int i = 0; i < n; i++) ans += memo[i];
	cout << ans << endl;
	return 0;
}