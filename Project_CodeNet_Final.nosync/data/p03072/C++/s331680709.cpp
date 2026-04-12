#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

	}

	for (int i = 1; i < n; i++) {
		bool f = true;
		for (int j = 0; j < i; j++) {
			if (a[i] < a[j]) {
				f = false;
				break;
			}
		}
		if (f) cnt++;
	}
	cout << cnt;

}