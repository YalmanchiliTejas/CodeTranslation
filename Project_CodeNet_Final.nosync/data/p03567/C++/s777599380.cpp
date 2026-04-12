#include <bits/stdc++.h>

using namespace std;

int main(void) {
	string S;
	cin >> S;
	for(int i = 0; i + 1 < S.length(); ++i) {
		if(S.substr(i, 2) == "AC") {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}

