#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int ans = 0;
	bool ok = true;

	for (int i = 0; i < n; i++) {
		ok = true;
		for (int j = 0; j < i; j++) {
			if (h[j] > h[i]) ok = false;;
		}
		if (ok) ans++;
	}

	cout << ans << endl;

	return 0;
}