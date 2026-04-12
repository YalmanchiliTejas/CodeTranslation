#include <iostream>

using namespace std;

void Solve() {
	string s;
	cin >> s;

	for (int i = 0; i + 1 < s.length(); ++i) {
		if (s[i] == 'A' && s[i+1] == 'C') {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main() {
	int tests = 1;

	for (;tests; --tests) {
		Solve();
	}
}