#include<iostream>

using namespace std;

int main(){
	char str;
	cin >> str;
	if(str == 'a' || str == 'e' || str == 'i' ||str == 'u' || str == 'o') cout << "vowel" << endl;
	else cout << "consonant" << endl;
	return 0;
}