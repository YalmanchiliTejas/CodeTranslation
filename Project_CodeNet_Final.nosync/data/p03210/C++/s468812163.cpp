#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int x;

	cin >> x;

	int a = x/2;
	int b = x%2;

	if(b==1)
	{
		if(a==1 || a==2 || a==3)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
	else
	{
		cout << "NO" << '\n';
	}
	return 0;
}