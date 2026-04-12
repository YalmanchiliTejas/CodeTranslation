#include <iostream>
#include <string>

using namespace std;

int main() {
	string s; cin >> s;
	bool flag = true;
	for (int i = 1; i < s.size(); ++i)
		if (s[i - 1] != s[i]) flag = false;
	cout << (flag ? "No" : "Yes") << endl;

	return 0;
}