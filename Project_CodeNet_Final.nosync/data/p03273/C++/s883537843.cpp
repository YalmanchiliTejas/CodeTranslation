#include <bits/stdc++.h>
using namespace std;


int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> sVec(H, vector<char>(W));

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> sVec.at(i).at(j);
		}
	}

	vector<bool> row(H, false);
	vector<bool> col(W, false);
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (sVec.at(i).at(j) == '#')
			{
				row.at(i) = true;
				col.at(j) = true;
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (row.at(i) && col.at(j))
			{
				cout << sVec.at(i).at(j);
			}
		}
		if (row.at(i))
		{
			cout << endl;
		}
	}
}