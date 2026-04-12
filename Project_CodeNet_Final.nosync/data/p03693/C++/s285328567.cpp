#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int r,g,b;

	cin >> r >> g >> b;

	int x = 100*r+10*g+b;

	if(x%4==0)
	{
		cout << "YES" << '\n';
	}
	else
	{
		cout << "NO" << '\n';
	}

	return 0;
}