#include<iostream>
#include<string>

using namespace std;

int main() {
	string s;
	cin >> s;
	char ss;
	int ans = 0;

	for (int i = 0; i < (int)s.size(); ++i) {
		char ch = s[i];
		if (i == 0) ss = ch;
		else {
			if (ch == ss);
			else ans = 1;
		}
	}
	if (ans == 0) {
		cout << "No" << endl;
	}
	else cout << "Yes" << endl;

	return 0;
}