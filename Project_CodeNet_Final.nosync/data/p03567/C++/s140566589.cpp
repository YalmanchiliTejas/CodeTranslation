#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	size_t pos;

	cin >> str;

	pos = str.find("AC");

	if (pos != string::npos)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}