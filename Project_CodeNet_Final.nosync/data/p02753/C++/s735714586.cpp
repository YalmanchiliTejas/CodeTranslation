#include <iostream>

using namespace std;

int main()
{
	char s[2];
	cin >> s;
	if (s[0] == s[1] && s[1] == s[2])
	{
		cout << "No";
	}
	else
	{
		cout << "Yes";
	}
	
}

