#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
// ceil() 切り上げ, floor() 切り捨て
// next_permutation(all(x))

int		main(void)
{
	int h, w;
	cin >> h >> w;

	char table[h][w];
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cin >> table[i][j];
	}

	vector<bool> row(h, true);
	for (int i = 0; i < h; i++)
	{
		bool f = false;
		for (int j = 0; j < w; j++)
		{
			if (table[i][j] == '#')
				f = true;
		}
		if (!f)
			row[i] = false;
	}

	vector<bool> column(w, true);
	for (int j = 0; j < w; j++)
	{
		bool f = false;
		for (int i = 0; i < h; i++)
		{
			if (table[i][j] == '#')
				f = true;
		}
		if (!f)
			column[j] = false;
	}

	for (int i = 0; i < h; i++)
	{
		bool f = false;
		for (int j = 0; j < w; j++)
		{
			if (row[i] && column[j])
			{
				cout << table[i][j];
				f = true;
			}
		}
		if (f)
			cout << endl;
	}
}

