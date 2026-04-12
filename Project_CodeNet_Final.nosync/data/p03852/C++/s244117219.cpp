#include <iostream>
#include <string>
using namespace std;

int main(void) {
	char c;
	string ans;

	cin >> c;

	ans = "vowel";
	switch (c) {
		case 'a' :
			break;
		case 'i' :
			break;
		case 'u' :
			break;
		case 'e' :
			break;
		case 'o' :
			break;
		default :
			ans = "consonant";
			break;
	}

	cout << ans << '\n';
	return 0;
}
