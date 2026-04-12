#include <iostream>

using namespace std;

int main()
{
	char C;
	cin >> C;

	switch (C)
	{
	case 'a':
	case 'i':
	case 'u':
	case 'e':
	case 'o':
		cout << "vowel" << endl;
		break;
	default:
		cout << "consonant" << endl;
		break;
	}
}
