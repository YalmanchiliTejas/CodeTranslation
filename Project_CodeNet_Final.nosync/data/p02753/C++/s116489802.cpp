#include <iostream>
using namespace std;

int main(void) {
	char s[3];
	cin >> s;
	if (s[0] == s[1] && s[1] == s[2]) cout << "No";
	else cout << "Yes";
	return 0;
}