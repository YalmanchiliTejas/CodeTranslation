#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	char	s[3];

	cin >> s[0] >> s[1] >> s[2];
	
	if (s[0] == s[1] && s[1] == s[2])
		cout << "No";
	else
		cout << "Yes";
}
