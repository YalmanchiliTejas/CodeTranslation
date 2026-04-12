#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	string S;
	cin >> S;
	cout << (S[0]==S[1] && S[0]==S[2] ? "No" : "Yes") << endl;
	return 0;
}
