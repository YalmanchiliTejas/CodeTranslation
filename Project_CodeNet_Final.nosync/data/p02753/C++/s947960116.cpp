#include <string>
#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	char station = s[0];
	bool yes = false;
	for (int i = 1; i < 3; i++) {
		if (s[i] != station) {
			yes = true;
			break;
		}
	}
	if (yes) cout << "Yes";
	else cout << "No";
	
	return 0;
}