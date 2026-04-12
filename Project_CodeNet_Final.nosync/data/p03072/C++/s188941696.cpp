#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	int ans = 0;
	int maxh = 0;
	for (int i = 0; i < n; i++) {
		int  h; cin >> h;
		if (maxh <= h) {
			maxh = h;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}