#include<iostream>

using namespace std;

int main() {
	string S;
	cin >> S;

	bool flag_AC = false;
	for (int i = 0; i < S.length() - 1; i++) {
		if (S[i] == 'A' && S[i + 1] == 'C') {
			flag_AC = true;
			break;
		}
	}

	if (flag_AC) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}
