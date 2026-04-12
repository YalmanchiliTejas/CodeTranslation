#include <bits/stdc++.h>
using namespace std;

int main() {
	//input
	string S;
	cin >> S;

	//output
	if (S[0] == S[1] && S[0] == S[2]) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}

	return 0;
}
