#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;

	int h_max = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int h; cin >> h;
		if (h_max <= h) ans++;
		h_max = max(h_max, h);
	}

	cout << ans << endl;
	return 0;
}