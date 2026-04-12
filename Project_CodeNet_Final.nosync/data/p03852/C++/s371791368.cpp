#include <iostream>
using namespace std;

int main() {
	char c;
	string ans;
	cin >> c;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
		ans = "vowel";
	}
	else {
		ans = "consonant";
	}
	cout << ans << endl;
}