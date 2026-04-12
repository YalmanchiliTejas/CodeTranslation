#include "bits/stdc++.h"
#include <string>
#define rep(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
using namespace std;

int main() {
	int l = 0, t = 0;
	string S;
	cin >> S;
	for (int i = 0; i < 3;i++) {
		if (S.at(i) == 'A') {
			l = 1;
		}if (S.at(i) == 'B') {
			t = 1;
		}
	}

	if (l + t == 2) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
