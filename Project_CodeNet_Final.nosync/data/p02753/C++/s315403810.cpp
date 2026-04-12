#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;

	bool f = true;
	for (auto &c : s)
	{
		f &= c == s[0];
	}

	cout << (f ? "No" : "Yes") << endl;

	return 0;
}