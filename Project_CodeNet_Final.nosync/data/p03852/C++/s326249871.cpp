#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	string S;
	cin >> S;
	if (S[0] == 'a' || S[0] == 'i' || S[0] == 'u' || S[0] == 'e' || S[0] == 'o') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
}