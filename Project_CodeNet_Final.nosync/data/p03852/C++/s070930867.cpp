#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	char vowel[] = { 'a','e','i','o','u' };
	char s; cin >> s;
	for (int i = 0; i < 5; i++) {
		if (s == vowel[i]) {
			cout << "vowel" << endl;
			return 0;
		}
	}
	cout << "consonant" << endl;
	return 0;
}