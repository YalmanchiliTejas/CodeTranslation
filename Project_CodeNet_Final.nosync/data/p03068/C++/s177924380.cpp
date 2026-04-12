//#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;


int main() {
	int n;
	string s;
	int k;
	cin >> n >> s >> k;
	char s2;
	s2 = s.at(k - 1);
	for (int i = 0; i < n; i++) {
		if (s.at(i) == s2) cout << s2;
		else cout << "*";
	}
	cout << endl;

}