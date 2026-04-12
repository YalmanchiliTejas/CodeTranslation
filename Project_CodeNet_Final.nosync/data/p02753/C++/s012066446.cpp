#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char ch[3];
	int a = 0, b = 0;
	for (int i = 0; i < 3; ++i)
	{
		cin >> ch[i];
		if (ch[i] == 'A')
		{
			a++;
		}
		else
			b++;
	}
	if (a != 3 && b != 3)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}
