#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define int long long

signed main() {
	char c;
	cin >> c;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
	return 0;
}

