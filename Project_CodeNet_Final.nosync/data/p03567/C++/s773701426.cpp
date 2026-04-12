#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	bool found = false;
	if (s.length() < 2)
		cout << "No" << endl;
	else {
		for (int i = 0; i <= (int)s.length() - 2; i++) {
			if (s.substr(i, 2).compare("AC") == 0) {
				cout << "Yes" << endl;
				found = true;
				break;
			}
		}
		if (!found)
			cout << "No" << endl;
	}

	return 0;
}
