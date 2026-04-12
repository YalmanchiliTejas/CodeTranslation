#include <bits/stdc++.h>
using namespace std;

int main() {
	int H;
	int W;

	cin >> H >> W;
	vector<string> strs(H);
	for (int i = 0; i < H; i++)
		cin >> strs.at(i);
	for (int i = 0; i < H; i++)
	{
		int count;

		count = 0;
		for (int j = 0; j < W; j++)
		{
			if (strs.at(i).at(j) == '.')
				count++;
		}
		if (count == W)
		{
			for (int j = 0; j < W; j++)
				strs.at(i).at(j) = 'N';
		}
	}
	for (int j = 0; j < W; j++)
	{
		int count;

		count = 0;
		for (int i = 0; i < H; i++)
		{
			if (strs.at(i).at(j) == '.' || strs.at(i).at(j) == 'N')
				count++;
		}
		if (count == H)
		{
			for (int i = 0; i < H; i++)
			{
				if (strs.at(i).at(j) == '.')
					strs.at(i).at(j) = 'N';
			}
		}
	}
	for (int i = 0; i < H; i++)
	{
		int count;

		count = 0;
		for (int j = 0; j < W; j++)
		{
			if (strs.at(i).at(j) != 'N')
			{
				cout << strs.at(i).at(j);
				count++;
			}
		}
		if (count != 0)
			cout << endl;
	}
}
