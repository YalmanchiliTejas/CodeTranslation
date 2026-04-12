#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long int n;
	cin >> n;
	vector<long long int> a(n);
	for (long long int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<long long int> b;
	if (n % 2 == 0) {
		for (long long int i = n - 1; i > 0; i -= 2) {
			b.push_back(a[i]);
		}
		for (long long int i = 0; i < n; i += 2) {
			b.push_back(a[i]);
		}
	}
	else {
		for (long long int i = n - 1; i >= 0; i -= 2) {
			b.push_back(a[i]);
		}
		for (long long int i = 1; i < n; i += 2) {
			b.push_back(a[i]);
		}
	}
	cout << b[0];
	for (long long int i = 1; i < n; i++) {
		cout << ' ' << b[i];
	}
	cout << endl;
	return 0;
}