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

	string ans;
	if (s == "AAA" || s == "BBB") {
		ans = "No";
	} else {
		ans = "Yes";
	}
	cout << ans << endl;

	return 0;
}
