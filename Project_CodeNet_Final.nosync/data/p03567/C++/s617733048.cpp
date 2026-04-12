#include "bits/stdc++.h"
using namespace std;

int main() {
	string s;
	cin >> s;

	int f = s.find("AC");

	if ( f != -1 ) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
