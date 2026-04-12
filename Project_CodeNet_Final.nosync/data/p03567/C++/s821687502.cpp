#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s.substr(i, 2) == "AC")
		{
			cout << "Yes\n"; return 0;
		}
	}
	cout << "No\n";
	return 0;
}
