#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	bool ok = false;
	if (s.find("AC") != string::npos) {
		ok = true;
	}

	cout << (ok ? "Yes" : "No") << endl;

	return 0;
}
