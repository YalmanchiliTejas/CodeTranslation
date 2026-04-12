#include <iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

int main() {
	string c;
	cin >> c;

	if (c == "a" || c == "i" || c == "u" || c == "e" || c == "o") {
		cout << "vowel" << endl;
	}

	else {
		cout << "consonant" << endl;
	}

	return 0;
}