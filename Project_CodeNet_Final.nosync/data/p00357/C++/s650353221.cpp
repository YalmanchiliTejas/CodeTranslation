#include <bits/stdc++.h>
using namespace std;
int a[1000005] = { 0 };
int b[1000005] = { 0 };
int main() {
	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i] + i * 10;
	}
	int m = b[0];
	for (int i = 1; i < n; i++) {
		if (10*i > m) {
			cout << "no" << endl;
			return 0;
		}
		else {
			m = max(m, b[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		b[i] = a[n - 1 - i] + i * 10;
	}
	m = b[0];
	for (int i = 1; i < n; i++) {
		if (10 * i > m) {
			cout << "no" << endl;
			return 0;
		}
		else {
			m = max(m, b[i]);
		}
	}
	cout << "yes" << endl;
}
