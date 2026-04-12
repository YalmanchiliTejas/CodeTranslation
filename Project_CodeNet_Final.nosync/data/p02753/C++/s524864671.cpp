#include "bits/stdc++.h"

using namespace std;

int main() {
	string S;
	cin >> S;
	int count = 0;

	for (int i = 0; i < 3; i++) {
		if (S[i] == 'A')count++;
	}
	if (count == 0 || count == 3)cout << "No";
	else cout << "Yes";
	return 0;
}