#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if (s[0] == s[2])
	{
		cout << "No";
	}
	else
	{
		cout << "Yes";
	}
}