// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int mx = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x >= mx) {
			ans++;
			mx = x;
		}
	}

	cout << ans;


	return 0;
}
