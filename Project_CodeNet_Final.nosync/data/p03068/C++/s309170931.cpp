#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k, n;
	char s[11];
	cin >> n;
	cin >> s;
	cin >> k;
	for (int i = 0; i < n; i++)
		if (s[i] != s[k - 1])
			s[i] = '*';
	cout << s;
	return 0;
}