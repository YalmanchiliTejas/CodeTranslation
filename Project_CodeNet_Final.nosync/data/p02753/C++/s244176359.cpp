#include <iostream>
using namespace std;

int main() {

	 char s[4];

	cin >> s;

	if (s[0] == 'A'&& s[1] == 'A' && s[2] == 'A') cout << "No\n";
	else if (s[0] == 'B'&& s[1] == 'B' && s[2] == 'B') cout << "No\n";
	else cout << "Yes\n";

	return 0;
}