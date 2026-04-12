#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>

using namespace std;

int main()
{
	string s;
	cin >> s;
	bool f = true;
	if (s[0] == s[1] &&s[1]==s[2]) {
		f = false;
	}
	if (f) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}