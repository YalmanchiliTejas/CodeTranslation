#include <iostream>
using namespace std;
int main() {
	while (1) {
		int n[5], ans = 0, m = 0;
		for (int i = 0; i < 5; i++) {
			int a, b;
			cin >> a >> b;
			if (a == 0 && b == 0) return 0;
			n[i] = a + b;
		}
		for (int i = 0; i < 5; i++) {
			if (m < n[i]) {
				m = n[i];
				ans = i;
			}
		}
		if (ans == 0) cout << "A " << m << endl;
		if (ans == 1) cout << "B " << m << endl;
		if (ans == 2) cout << "C " << m << endl;
		if (ans == 3) cout << "D " << m << endl;
		if (ans == 4) cout << "E " << m << endl;
	}
	return 0;
}