#include<bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(0),cin.tie(0);
char a[101][101];
int main()
{
  fastio();
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)cin >> a[i];
	for (register int i = 0; i < r; i++)
	{
		bool erase = true;
		for (register int j = 0; j < c;j++)
		{
			if (a[i][j] == '#')
			{
				erase = false;
				break;
			}
		}
		if (erase)continue;
		for (register int j = 0; j < c; j++)
		{
			erase = true;
			for (register int k = 0; k < r; k++)
			{
				if (a[k][j] == '#')
				{
					erase = false;
					break;
				}
			}
			if (!erase)cout << a[i][j];
		}
		cout << "\n";
	}
	return 0;
}