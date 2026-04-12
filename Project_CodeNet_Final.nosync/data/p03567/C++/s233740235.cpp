#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	string s;
	bool a = 0;
	cin >> s;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == 'A' && s[i + 1] == 'C') a = 1;
	}
	cout << (a?"Yes":"No");
	return 0;
}

