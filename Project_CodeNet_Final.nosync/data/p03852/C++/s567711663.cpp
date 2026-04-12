#include<iostream>

using namespace std;

int main() {
	char v[6] = { 'a','e','i','o','u' };
	char c;
	cin >> c;

	int j = 0;
	for (int i = 0; i < 5; i++) {
		if (c == v[i]) {
			j = 1;
			break;
		}
	}
	if (j == 1)cout << "vowel" << endl;
	else cout << "consonant" << endl;

	return 0;
}