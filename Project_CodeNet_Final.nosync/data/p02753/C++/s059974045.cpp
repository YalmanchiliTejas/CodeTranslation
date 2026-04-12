#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	if (s[0]==s[1] && s[1]==s[2])
		cout << "No";
	else
		cout << "Yes";
	cout << endl;
	return 0;
}