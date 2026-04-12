#include<iostream>
#include<string>
using namespace std;

int main() {
	int x, y, z;
	char s;
	cin >> s;
	if (s == 'a' || s == 'i' || s == 'o' || s == 'u' || s == 'e')cout << "vowel" << endl;
	else cout << "consonant"<<endl;
	
	return 0;
}