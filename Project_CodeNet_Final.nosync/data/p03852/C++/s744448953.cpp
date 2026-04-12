#include <iostream>
using namespace std;
int main() {
	string S;
		cin >> S;
	if (S == "a" || S == "i" || S == "u" || S == "e" || S == "o") {
		cout << "vowel" << endl;
	}else {
		cout << "consonant" << endl;
	}
}