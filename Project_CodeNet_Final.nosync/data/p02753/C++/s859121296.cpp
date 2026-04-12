#include<iostream>
#include<string>
using namespace std;

int main() {
	int flag = 0;
	char S[3];
	for (int i = 0; i < 3; i++) cin >> S[i];

	if (S[0] == 'A') {
		for (int i = 0; i < 3; i++) {
			if (S[i] == 'B') flag = 1;
		}
	}

	if (S[0] == 'B') {
		for (int i = 0; i < 3; i++) {
			if (S[i] == 'A') flag = 1;
		}
	}

	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}