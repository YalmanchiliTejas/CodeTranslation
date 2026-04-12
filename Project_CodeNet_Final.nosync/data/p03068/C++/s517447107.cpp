#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	string s;
	cin >> n >> s >> k;
	char x = s.at(k - 1);
	for (int i = 0; i < n; i++)
	{
		if (s.at(i) != x)
			s.at(i) = '*';
	}
	cout << s << endl;
	return 0;
}