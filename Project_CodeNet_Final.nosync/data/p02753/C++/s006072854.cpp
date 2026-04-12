#include <iostream>
using namespace std;

char s[4];

int main()
{
	cin >> s;

	if(s[0] == s[1] && s[1] == s[2])
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}
