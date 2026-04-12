#include <bits/stdc++.h>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	int r[H] = {0}, c[W] = {0};
	vector<vector<char>> T(H, vector<char>(W));
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
		{
			cin >> T[i][j];
			if (T[i][j] == '#')
				r[i]++, c[j]++;

		}

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			if (r[i] && c[j])
				cout << T[i][j];
		}
		if (r[i])
			cout << endl;
	}
}
