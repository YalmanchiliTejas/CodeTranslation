#include <bits/stdc++.h>
using namespace std;

int main() {
	char c;
	cin >> c;
	vector <char> vowel(5);
	vowel = { 'a', 'i', 'u', 'e', 'o' };
	
	int check = 0;
	for (int i = 0; i < vowel.size(); i++) {
		if(vowel[i] == c) { check = 1; }
	}
	if(check) {
		cout << "vowel" << endl;
	} else {
		cout << "consonant" << endl;
	}
}