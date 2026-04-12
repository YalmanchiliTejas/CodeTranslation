#include <iostream>
using namespace std;
int main() {
	char X;
	cin >> X;
	
	if (X == 'a' || X == 'i' || X == 'u' || X == 'e' || X == 'o') {
		cout << "vowel" << endl;
	}
	
	else {
		cout << "consonant" << endl;
	}
}