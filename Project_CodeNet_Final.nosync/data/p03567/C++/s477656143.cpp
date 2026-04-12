#include <bits/stdc++.h>
using namespace std;
int main() {
	string S;
	cin >> S;
	for(int i = 0; i < S.length() - 1; i++) {
		if(S.substr(i,2) == "AC") {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}