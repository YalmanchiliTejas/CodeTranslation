#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	cin >> s;

	bool flag = false;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == 'A' && s[i + 1] == 'C')flag = true;
	}

	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}