#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> o(n);
	for (int i = 0; i < n; i++) {
		cin >> o[i];
	}
	int ans = 1;
	int h = o[0];
	for (int i = 1; i < n; i++) {
		if(h <= o[i]) {
			ans++;
			h = o[i];
		}
	}
	cout << ans << endl;
	return 0;
}
