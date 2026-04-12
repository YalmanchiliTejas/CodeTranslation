#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if(n == 1) {
		cout << a[0] << endl;
	} else {
		for(int i = n - 1; 0 <= i; i -= 2) {
			cout << a[i] << " ";
		}
		if(n % 2 == 0) {
			for(int i = 0; i < n; i += 2) {
				cout << a[i];
				if(i == n - 2) {
					cout << endl;
				} else {
					cout << " ";
				}
			}
		} else {
			for(int i = 1; i < n; i += 2) {
				cout << a[i];
				if(i == n - 1) {
					cout << endl;
				} else {
					cout << " ";
				}
			}
		}
	}

	return 0;
}