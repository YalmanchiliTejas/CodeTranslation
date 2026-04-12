#include <iostream>
#include <vector>

using namespace std;

void Solve() {
	int n;
	cin >> n;

	vector<int> a(n+1), b(n+1);

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = n; i >= 1; --i) {
		if ((n-i)&1) {
			b[n - (n-i)/2] = a[i];
		} else {
			b[(n-i)/2 + 1] = a[i];
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << b[i] << " ";
	}
	cout << "\n";
}

int main() {
	int tests = 1;
	for (;tests; --tests) {
		Solve();
	}
}