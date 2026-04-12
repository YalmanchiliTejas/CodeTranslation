#include<iostream>
#include<string>

using namespace std;
int main()
{
	char ls;
	string ans;

	cin >> ls;

	switch (ls) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		ans = "vowel";
		break;

	default:
		ans = "consonant";
		break;
	}
	
	cout << ans << endl;

	return 0;
}