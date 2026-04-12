#include <iostream>

using namespace std;

char S[10] = {};

int main() {
	cin >> S;
	for (int i = 1; i < 6; i++) {
		if (S[i] == NULL) {
			cout << "No" << endl;
			return 0;
		}
		else if (S[i] == 'C' && S[i - 1] == 'A') {
			cout << "Yes" << endl;
			return 0;
		}
	}
}