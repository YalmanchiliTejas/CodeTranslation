#include "bits/stdc++.h"
using namespace std;

int main() {
	string S = "\0";
	int n = 0, ans = 0;
	cin >> S;
	for (int i = 0; i < 2; i++) {
		if (S[i] != S[i + 1])ans = 1;
	}
	if (ans == 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}