#include <iostream>
using namespace std;

int main()
{
	char c;
	cin >> c;
	bool v = false;
	switch(c){
		case 'a': case 'e': case 'i': case 'o': case 'u':
			v = true;
			break;
	}
	cout << (v ? "vowel" : "consonant") << endl;
	return 0;
}