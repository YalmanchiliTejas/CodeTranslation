#include <bits/stdc++.h>

using namespace std;

int h, w;
char grid[10][10];

int main()
{
	cin >> h >> w;
	for (int r = 0; r < h; r++)
		for (int c = 0; c < w; c++)
			cin >> grid[r][c];
	int l = 0;
	for (int r = 0; r < h; r++)
	{
		int state = 0;
		for (int c = 0; c < w; c++)
		{
			if (!state && grid[r][c] == '#')
			{
				if (c != l) {
					cout << "Impossible\n";
					return 0;
				}
				state++;
			}
			else if (state == 1)
			{
				if (grid[r][c] == '.') state++;
				else l++;
			}
			else if (state == 2 && grid[r][c] == '#') {
				cout << "Impossible\n";
				return 0;
			}
		}
	}
	cout << "Possible\n";
	return 0;
}

