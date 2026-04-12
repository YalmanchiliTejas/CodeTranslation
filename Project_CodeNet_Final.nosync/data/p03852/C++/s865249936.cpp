#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	char a;
	cin >> a;

	switch(a)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			cout << "vowel" << endl;
			break;
		default:
			cout << "consonant" << endl;
	}	

	return 0;
}