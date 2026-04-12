#include "bits/stdc++.h"
#include <string>
#define rep(i,n) for(int (i) = 0; (i) < (n) ; (i)++)
using namespace std;

int main() {
	char c;
	cin >> c;
	const string vowel = "aeiou";
	vowel.find(c) == string::npos ? cout << "consonant" << endl : cout << "vowel" << endl;
	}