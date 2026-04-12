#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
	string s;
	cin >> s;
	bool ans = true;
	for (auto ch : s)
		if (s[0] != ch) ans = false;

	if (ans == true)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}