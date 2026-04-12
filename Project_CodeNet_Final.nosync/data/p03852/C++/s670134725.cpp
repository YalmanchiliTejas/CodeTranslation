#include <iostream>
using namespace std;

char x[] = { 'a', 'i', 'u', 'e', 'o' };

int main() {
	bool flag = false;
	char c;
	cin >> c;
	for (int i = 0; i < 5; i++) {
		if (x[i] == c)flag = true;
	}

	if (flag) {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
}