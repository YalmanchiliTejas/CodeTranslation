#include<iostream>

using namespace std;

int main() {
	char c;
	cin >> c;
	switch (c)
	{
	case 'a':
	case'i':
	case 'u':
	case'e':
	case'o':
		cout << "vowel";
			break;
	default:
		cout << "consonant";
		break;
	}

	return 0;
}