#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string S;
	cin >> S;

	if ((S[0] == 'A') && (S[1] == 'A') && (S[2] == 'A')){
		cout << "No" << endl;
		return 0;
	}
	if ((S[0] == 'B') && (S[1] == 'B') && (S[2] == 'B')){
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << "\n";

	return 0;
}
