#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
	char c;
	cin >> c;

	switch (c) {
	case 'a':
	case 'e':
	case 'i':
	case 'u':
	case 'o':
		cout << "vowel";
		break;
	default:
		cout << "consonant";
	}

	cout << endl;

	return 0;
}
