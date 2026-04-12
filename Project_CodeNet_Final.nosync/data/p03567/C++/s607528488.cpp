#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	bool IsAC = false;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'A') {
			if (S[i + 1] == 'C')
				IsAC = true;
		}
	}
	if (IsAC == true) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}