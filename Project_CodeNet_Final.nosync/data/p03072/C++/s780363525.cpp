#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	rep(i, n) cin >> h[i];

	int ans = 1;
	int mx = h[0];
	rep(i, n - 1) {
		if (mx <= h[i + 1]) ans++;
		mx = max(mx, h[i + 1]);

	}
	cout << ans << endl;
}