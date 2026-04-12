#include <iostream>
using namespace std;

int main() {
	// your code goes here
	char c;
	cin >> c;
	if((c=='a')||(c=='e')||(c=='o')||(c=='u')||(c=='i')){
		cout << "vowel" << endl;
	}
	else cout << "consonant" << endl;
	
	return 0;
}