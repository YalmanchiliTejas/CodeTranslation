#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string str;
	string base = "aiueo";
	cin >> str;
	if (base.find(str) <= 4) {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
	return 0;
}