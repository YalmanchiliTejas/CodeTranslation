#include <bits/stdc++.h>
using namespace std;

int main () {

	int n;
	cin >> n;

	int ans = 0;
	int maxi = -1;

	for (int i = 0; i < n; ++i) {
		int x;
		scanf ("%d", &x);
		maxi = max (x, maxi);
		if (x == maxi) ++ans;
	}

	cout << ans << endl;

	return 0;
}