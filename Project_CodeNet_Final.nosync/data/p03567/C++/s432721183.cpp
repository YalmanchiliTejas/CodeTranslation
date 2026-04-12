#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	bool check = false;
	cin >> S;
	for (int i = 0; i < S.size() - 1; i++) {
		if (S[i] == 'A' && S[i + 1] == 'C') check = true;
	}
	if (check) cout << "Yes" << endl;
	else cout << "No" << endl;
}