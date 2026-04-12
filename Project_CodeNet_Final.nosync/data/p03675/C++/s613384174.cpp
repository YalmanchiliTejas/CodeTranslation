#include <iostream>

using namespace std;

#define MAX_N 200000

int n;
int a[MAX_N];

void solve() {
	if (n == 1) {
		cout << a[0] << endl; return;
	}
	if (n % 2 == 0) {
		for (int i = n - 1; i >= 1; i -= 2) cout << a[i] << ' ';
		for (int i = 0; i <= n - 4; i += 2) cout << a[i] << ' ';
		cout << a[n - 2] << endl;
	}
	else {
		for (int i = n - 1; i >= 0; i -= 2) cout << a[i] << ' ';
		for (int i = 1; i <= n - 3; i += 2) cout << a[i] << ' ';
		cout << a[n - 2] << endl;
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	solve();

	return 0;
}