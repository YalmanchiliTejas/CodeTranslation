#include <iostream>
#include<sstream>
#include<vector>
#include<iterator>
using namespace std;

int main(void)
{
	char c;
	cin >> c;

	string ret;
	const string str("aiueo");
	if(str.find(c) == string::npos)
		ret = "consonant";
	else
		ret = "vowel";

	cout << ret << endl;

	return 0;
}
