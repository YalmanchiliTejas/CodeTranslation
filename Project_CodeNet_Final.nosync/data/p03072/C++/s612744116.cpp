#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)

signed main() {
	int n;
	cin >> n;
	int ans = 0;
	int now = 0;
	rep(i, n) {
		int w;
		cin >> w;
		if(w >= now) {
			ans++;
		}
		now = max(now, w);
	}
	cout << ans << endl;
}