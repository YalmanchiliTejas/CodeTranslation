#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char s[3];
	cin >> s;
	if (!strcmp(s, "AAA") || !strcmp(s, "BBB"))
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}