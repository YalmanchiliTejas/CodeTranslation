#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	string L = "qwertasdfgzxcvb", R = "yuiophjklnm";
	int C[26] = {};
	for (int i = 0; i < R.size(); i++) C[R[i] - 'a'] = 1;
	while (cin >> S) {
		if (S == "#") return 0;
		int ANS = 0;
		for (int i = 0; i < S.size() - 1; i++) ANS += abs(C[S[i] - 'a'] - C[S[i + 1] - 'a']);
		cout << ANS << endl;
	}
}
