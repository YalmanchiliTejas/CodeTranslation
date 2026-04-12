#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, a[100], ta = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1;; i++) {
		for (int j = 0; j < n; j++) {
			ta += a[j];
			ta -= i;
			if (ta < 0) {
				cout << i - 1 << endl;
				return 0;
			}
		}
		ta = 0;
	}
}
