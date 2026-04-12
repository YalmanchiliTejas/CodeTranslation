#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, a, b;
	cin >> x >> a >> b;
	if ((10 * a + b) % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}