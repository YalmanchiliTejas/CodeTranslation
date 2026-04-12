#include<iostream>

using namespace std;

int main() {
	char c;

	//入力
	cin >> c;

	//母音か判定
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
}