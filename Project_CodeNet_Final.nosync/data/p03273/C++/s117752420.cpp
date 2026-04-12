#include <iostream>
#include <string>
using namespace std;


int main()
{
	int h,w;
	cin >> h >> w;
	char a[h][w];
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> a[i][j];
		}
	}
	int deleteRow[h];
	int rowCount = 0;
	for (int i = 0; i < h; i++)
	{
		bool allWhite = true;
		for (int j = 0; j < w; j++)
		{
			if (a[i][j] == '#') allWhite = false;
		}
		if (allWhite)
		{
			deleteRow[rowCount] = i;
			rowCount++;
		}
	}
	int deletecol[w];
	int colcount = 0;
	for (int j = 0; j < w; j++)
	{
		bool allWhite = true;
		for (int i = 0; i < h; i++)
		{
			if (a[i][j] == '#') allWhite = false;
		}
		if (allWhite)
		{
			deletecol[colcount] = j;
			colcount++;
		}
	}
	for (int i = 0; i < h; i++)
	{
		bool show = true;
		bool shown = true;
		for (int p = 0; p < rowCount; p++)
		{
			if (i == deleteRow[p]) show = false;
		}
		for (int j = 0; j < w; j++)
		{
			bool show2 = true;
			for (int q = 0; q < colcount; q++)
			{
				if (j == deletecol[q]) show2 = false;
			}
			if (show && show2) cout << a[i][j];

		}
		if (show) cout<< endl;
	}
}