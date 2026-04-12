#include <iostream>
using namespace std;
int main() {
	char s[1];
	cin >> s[0];
	if(s[0]==0x61||s[0]==0x65||s[0]==0x69||s[0]==0x6f||s[0]==0x75){
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
	return 0;
}