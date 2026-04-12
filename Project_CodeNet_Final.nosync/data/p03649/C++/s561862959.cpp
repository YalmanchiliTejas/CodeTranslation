#include <bits/stdc++.h>
using namespace std;

signed main () {
	int n; 
	cin >> n;
	vector < long long > a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	long long ans = 0;
	while (*max_element(a.begin(), a.end()) >= n) {
		long long mx = 0;
		int j = -1;
		for (int i = 0; i < n; ++i) {
			if (a[i] > mx) 
				mx = a[i], j = i;
		}
		for (int i = 0; i < n; ++i) {
			if (i != j) 
				a[i] += (mx / n);
		}
		a[j] -= (mx / n) * n;
		ans += mx / n;
	}
	cout << ans << endl;
}
