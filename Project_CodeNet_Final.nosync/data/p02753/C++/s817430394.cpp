#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

void redir() {
	#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
	#endif
}

bool connected(const string &s) {
	if (s.length() <= 1)
		return false;

	size_t i = 0;
	char last = s[i];
	for (i++; i < s.length(); i++) {
		char c = s[i];
		if (c != last) {
			return true;
		} else {
			last = c;
		}
	}

	return false;
}

void solve() {
	string S;
	cin	>> S;

	cout << (connected(S) ? "Yes" : "No") << endl;
}

int main() {
	
	solve();
}