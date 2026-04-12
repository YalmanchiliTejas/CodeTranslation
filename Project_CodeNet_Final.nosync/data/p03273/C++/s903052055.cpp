#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;

	vector<vector<char>> m;
	for (auto i = 0; i < H; ++i)
	{
		vector<char> w;
		auto isExist = false;
		for (auto j = 0; j < W; ++j)
		{
			char a;
			cin >> a;
			w.push_back(a);
			if (a == '#')
			{
				isExist = true;
			}
		}
		if (isExist)
		{
			m.push_back(w);
		}
	}

	vector<int> c;
	for (auto i = 0; i < W; ++i)
	{
		for (auto j = 0; j < m.size(); ++j)
		{
			if (m[j][i] == '#')
			{
				c.push_back(i);
				break;
			}
		}
	}

	for (auto i = 0; i < m.size(); ++i)
	{
		for (auto j = 0; j < c.size(); ++j)
		{
			cout << m[i][c[j]];
		}
		cout << endl;
	}

	return 0;
}
