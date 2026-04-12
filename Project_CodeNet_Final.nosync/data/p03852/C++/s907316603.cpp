#include <iostream>

using namespace std;

static bool isVowel(const char c) {
	bool ret = false;

	switch (c) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		ret = true;
		break;
	default:
		ret = false;
		break;
	}
	return ret;
}

int main() {
	char c;

	cin >> c;

	if (isVowel(c)) {
		cout << "vowel" << endl;
	} else {
		cout << "consonant" << endl;
	}

	return 0;
}
