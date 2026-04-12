#include "bits/stdc++.h"
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> brd(h);

	for (int i = 0; i < h; i++)
	{
			cin >> brd.at(i);
	}
	vector<vector<int>> cnt(2, vector<int>(max(w,h)));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (brd.at(i).at(j) == '.') {
				cnt.at(0).at(i)++; cnt.at(1).at(j)++;
			}
		}
	}
	for (int i = 0; i < h; i++)
	{
		if (cnt.at(0).at(i) < w) 
		{
			for (int j = 0; j < w; j++)
			{
				if (cnt.at(1).at(j) < h)
				{
					cout << brd.at(i).at(j);
				}
			}

		cout << endl;
		}
	}
}
