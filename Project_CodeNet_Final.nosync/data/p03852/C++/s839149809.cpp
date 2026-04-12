#include <iostream>

using namespace std;

int main(void)
{
    char input;

	cin >> input;

	switch(input)
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

    return 0;
}
