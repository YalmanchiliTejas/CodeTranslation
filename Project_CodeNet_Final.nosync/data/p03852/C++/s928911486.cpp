#include<iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string buf;

	// cin >> buf;

	cin >> buf;

	regex re("[aiueo]");

	if (regex_match(buf, re)){
		cout << "vowel ";
	}
	else
	{
		cout << "consonant";
	}
	
	// system("pause");

	return 0;
}

