#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	int ans = 0;
	int mx = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (mx <= h[i]) {
			mx = h[i];
			ans++;
		}
	}

	cout << ans << endl;
}


