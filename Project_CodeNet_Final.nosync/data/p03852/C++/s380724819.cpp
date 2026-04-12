#include <bits/stdc++.h>
using namespace std;

int main() {
	const string vowel = "aiueo";
	char character;
	cin >> character;

	if ( vowel.find(character) != string::npos){
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}