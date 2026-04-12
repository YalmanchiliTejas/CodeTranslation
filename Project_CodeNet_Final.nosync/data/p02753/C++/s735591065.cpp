#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	bool a = false;
	bool b = false;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'A') {
			a = true;
		}
		if (s[i] == 'B') {
			b = true;
		}
	}
	if (a&&b) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}