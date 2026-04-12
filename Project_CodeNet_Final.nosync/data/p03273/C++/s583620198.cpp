#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <limits>
#include <numeric>
#include <algorithm>
#include <functional>

#include <set>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int H, W;
	cin >> H >> W;

	vector<vector<int>> map_info(H, vector<int>(W, 0));
	for (int i = 0; i < H; i++)
	{
		string line;
		cin >> line;

		for (int j = 0; j < W; j++)
		{
			map_info[i][j] = (line[j] == '.');
		}
	}

	int limit = 0;
	while (limit < 200)
	{
		set<int> delete_row;
		for (int i = 0; i < map_info.size(); i++)
		{
			bool check = true;
			for (int j = 0; j < map_info[i].size(); j++)
			{
				if (map_info[i][j] != 1)
				{
					check = false;
					break;
				}
			}

			if (check) delete_row.insert(i);
		}

		set<int> delete_col;
		for (int j = 0; j < map_info[0].size(); j++)
		{
			bool check = true;
			for (int i = 0; i < map_info.size(); i++)
			{
				if (map_info[i][j] != 1)
				{
					check = false;
					break;
				}
			}

			if (check) delete_col.insert(j);
		}

		if (delete_row.size() == 0 && delete_col.size() == 0) break;

		vector<vector<int>> n_map_info(map_info.size() - delete_row.size(), vector<int>(map_info[0].size() - delete_col.size(), 0));
		int ni = 0;
		int nj = 0;
		for (int i = 0; i < map_info.size(); i++)
		{
			if (delete_row.find(i) != delete_row.end()) continue;
			for (int j = 0; j < map_info[i].size(); j++)
			{
				if (delete_col.find(j) != delete_col.end()) continue;

				n_map_info[ni][nj] = map_info[i][j];
				nj++;
			}
			ni++;
			nj = 0;
		}

		map_info = n_map_info;
	}

	for (int i = 0; i < map_info.size(); i++)
	{
		for (int j = 0; j < map_info[i].size(); j++)
		{
			if (map_info[i][j] == 1) cout << ".";
			else cout << "#";
		}
		cout << "\n";
	}

	return 0;
}
