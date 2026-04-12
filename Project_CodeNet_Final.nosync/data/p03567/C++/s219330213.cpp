#include <iostream>
#include <string>

using namespace std;

int main() {

	string s;
	cin >> s;

	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'A' && s[i+1] == 'C') {
			cout << "Yes" << endl;
			n = 0;
			break;
		}
	}
	if (n != 0) {
		cout << "No" << endl;
	}
}
	