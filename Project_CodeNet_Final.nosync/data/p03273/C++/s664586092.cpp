#include <bits/stdc++.h>
using namespace std;

bool isRow(vector<vector<char>> r, int i)
{
	for (int j = 0; j < r[0].size(); ++j)
	{
		if (r[i][j] != '.')
		{
			return false;
			break;
		}
	}
	return true;
}

bool isColumn(vector<vector<char>> r, int j)
{
	for (int i = 0; i < r.size(); ++i)
	{
		if (r[i][j] != '.')
		{
			return false;
			break;
		}
	}
	return true;
}

int main()
{
	int H, W;
	cin >> H >> W;
	vector<vector<char>> T(H, vector<char>(W));
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			cin >> T[i][j];

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			if (isColumn(T, j))
				continue;
			else if (isRow(T, i)) 
				goto skip;	
			else
				cout << T[i][j];
		}
		cout << endl;
        skip:{} 
	}
}
