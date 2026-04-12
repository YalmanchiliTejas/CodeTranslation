#include <iostream>
using namespace std;
#include <string>

int main() {
	string c;
	cin >> c;
	
	string aeiou = "aeiou";
	
	if(aeiou.find(c) == string::npos) cout << "consonant";
	else cout << "vowel";

	cout << endl;
	
	return 0;
}