#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int H, W;

	cin >> H >> W;
	vector<string> table(H);
	vector<int> flag_row(H);
	vector<int> flag_column(W);
	for (int i = 0; i < H; i++)
		cin >> table[i];
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (table[i][j] == '#')
			{
				flag_row[i] = 1;
				flag_column[j] = 1;
			}
		} 
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (flag_row[i] == 1 && flag_column[j] == 1)
				cout << table[i][j];
		} 
		if (flag_row[i] == 1)
			cout << endl;
	}
}
