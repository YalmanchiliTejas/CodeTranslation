#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
	char obj;
	bool flag = false;
	string vow = "aiueo";
	cin >> obj;
	
	rep (i, vow.size()) {
		if (obj == vow.at(i)) {
			flag = true;
		}
	}
	if (flag == true) {
		cout << "vowel" << endl;
	} else {
		cout << "consonant" << endl;
	}
	return 0;
}
