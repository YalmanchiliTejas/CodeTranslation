#include<iostream>
using namespace std;

int main(){
	char s; cin >> s;
	cout << (s == 'a' || s == 'i' || s == 'u' || s == 'e' || s == 'o' ? "vowel\n" : "consonant\n");
	return 0;
}