#include <iostream>

using namespace std;

int main(void)
{
	char c;
	cin >> c;
	switch (c) {
	case 'a':
	case 'o':
	case 'e':
	case 'i':
	case 'u':
		cout << "vowel" << endl;
		break;
	default:
		cout << "consonant" << endl;
		break;
	}
	return 0;
}
