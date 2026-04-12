#include <iostream>
using namespace std;

int main() {
	char ans[5] = { 'a','i','u','e','o' };
	char c;
	cin >> c;
	for (char a : ans) if (c == a) {
		cout << "vowel" << endl;
		return 0;
	}
	cout << "consonant" << endl;
}