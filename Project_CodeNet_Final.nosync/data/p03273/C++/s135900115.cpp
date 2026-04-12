#include <iostream>
#include <string>
using namespace std;
int main()
{
	int H, W;
	cin >> H >> W;
	string a[110];
	for (int i = 0; i < H; i++)
	{
		cin >> a[i];
	}

	bool line[110] = { false }, row[110] = { false };
	
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (a[i][j] == '#')
			{
				line[i] = true;
				break;
			}
		}
	}
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (a[j][i] == '#')
			{
				row[i] = true;
				break;
			}
		}
	}
	for (int i = 0; i < H; i++)
	{
		if (line[i])
		{
			for (int j = 0; j < W; j++)
			{
				if(row[j])
				cout << a[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}