#include <iostream>
#include <string>

using namespace std;

int main() {
	char c;
	string abc = "aiueo";
	cin >> c;
	bool h = false;
	for (int i = 0; i < abc.size(); i++) {
		if (abc[i] == c) {
			h = true;
			break;
		}
	}
	if (h) {
		cout << "vowel" << endl;
	} else {
		cout << "consonant" << endl;
	}
	return 0;
}