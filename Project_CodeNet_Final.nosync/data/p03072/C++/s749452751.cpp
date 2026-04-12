#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0, maxVal = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] >= maxVal) ans++, maxVal = a[i];
	}
	cout << ans << endl;
	return 0;
}