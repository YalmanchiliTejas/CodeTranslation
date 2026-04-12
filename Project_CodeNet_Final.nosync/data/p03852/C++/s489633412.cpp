#include<iostream>
using namespace std;
int main(){
	char l;
	cin >> l;
	if (l == 'a' || l == 'e' || l == 'o' || l == 'i' || l == 'u') {
		cout << "vowel";
	}
	else {
		cout << "consonant";
	}
	return 0;
}