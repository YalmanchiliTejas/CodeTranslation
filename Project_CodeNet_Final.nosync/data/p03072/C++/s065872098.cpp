#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int h[30];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (h[i] < h[j]) {
				goto LABEL;
			}
		}
		// cout << i << endl;
		ans++;
LABEL: ;
	}
	cout << ans << endl;
}
