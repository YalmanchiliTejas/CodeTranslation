#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	char c;
	cin >> c;
	const string vowel = "aiueo";
	if (vowel.find(c) != string::npos) cout << "vowel" << endl;
	else cout << "consonant" << endl;
	return 0;
}
