#include <iostream>
using namespace std;

string is_vowel(char);

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	char c;
	cin >> c;
	
	cout << is_vowel(c);
	
	return 0;
}

string is_vowel(char c){
	switch(c){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return "vowel";
		default:
			return "consonant";
	}
}