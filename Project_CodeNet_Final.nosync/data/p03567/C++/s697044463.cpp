#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	string S;
	bool b = false;

	cin >> S;

	for (int i = 1; i < (int)S.size(); i++) {
		if (S[i] == 'C' && S[i-1] == 'A') b = true;
	}

	if (b) {
		cout << "Yes" << endl;

	}
	else {
		cout << "No" << endl;
	}



	return 0;
}
