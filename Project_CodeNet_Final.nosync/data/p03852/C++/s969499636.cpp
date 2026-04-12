#include<iostream>
#include<string>
using namespace std;

int main() {
	char c;
	int flg;
	string sr[2] = { "vowel","consonant" };
	cin >> c;
	if (c == 'a'||c=='i'||c=='e') { flg = 0; }
	else if (c == 'o' || c == 'u') { flg = 0; }
	else { flg = 1; }
	cout << sr[flg] << endl;
	return 0;
}