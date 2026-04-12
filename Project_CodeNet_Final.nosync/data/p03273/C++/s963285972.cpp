#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef char GRID;

#define WHITE '.'
#define BLACK '#'

int main()
{
	int H, W;
	cin >> H >> W;

	vector<vector<GRID>> grid(H, vector<GRID>(W));

	for (int Hi = 0; Hi < H; Hi++)
	{
		for (int Wi = 0; Wi < W; Wi++)
		{
			cin >> grid.at(Hi).at(Wi);
		}
	}

	for (int Hi = 0; Hi < H; Hi++)
	{
		int AmountOfWhite;	AmountOfWhite = 0;
		for (int Wi = 0; Wi < W; Wi++)
		{
			if (grid.at(Hi).at(Wi) == WHITE) AmountOfWhite++;
		}

		if (AmountOfWhite == W)
		{
			for (int Wi = 0; Wi < W; Wi++)
			{
				grid.at(Hi).at(Wi) = EOF;
			}
		}
	}
	
	for (int Wi = 0; Wi < W; Wi++)
	{
		int AmountOfWhite; AmountOfWhite = 0;
		for (int Hi = 0; Hi < H; Hi++)
		{
			if ((grid.at(Hi).at(Wi) == WHITE) || (grid.at(Hi).at(Wi) == EOF)) AmountOfWhite++;
		}

		if (AmountOfWhite == H)
		{
			for (int Hi = 0; Hi < H; Hi++)
			{
				grid.at(Hi).at(Wi) = EOF;
			}
		}
	}

	bool doPrint;
	for (int Hi = 0; Hi < H; Hi++)
	{
		doPrint = false;
		for (int Wi = 0; Wi < W; Wi++)
		{
			if (!(grid.at(Hi).at(Wi) == EOF))
			{
				cout << grid.at(Hi).at(Wi);
				doPrint = true;
			}
		}
		if (doPrint == true) cout << endl;
	}

	return 0;
}