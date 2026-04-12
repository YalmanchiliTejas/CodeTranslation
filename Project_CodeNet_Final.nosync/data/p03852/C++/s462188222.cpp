#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	char c;
	char ans[5] = { 'a','i','u','e','o' };
	cin >> c;
	for (int i = 0; i < 5; i++) {
		if (c == ans[i]) {
			cout << "vowel" << endl;
			return 0;
		}
	}
	cout << "consonant" << endl;
	return 0;
}