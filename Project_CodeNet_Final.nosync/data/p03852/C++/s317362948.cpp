#include <iostream> 
using namespace std;

int main() {
	string a ; 
	cin >> a ;
	if (a == "a" || a == "e" || a == "o" || a == "i" || a == "u") {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
	return 0;
}