#include <bits/stdc++.h>
using namespace std;

int main() {
	char c;
	string s = "consonant";
	cin >> c;
	if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
		s = "vowel";
	}
	cout << s << endl;
}
