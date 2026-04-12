#include <iostream>
using namespace std;

int main() {
	char c;
	cin >> c;
	if ((c-'a'==0)or(c-'e'==0)or(c-'i'==0)or(c-'o'==0)or(c-'u'==0)) cout << "vowel" << endl;
	else cout << "consonant" << endl;
}