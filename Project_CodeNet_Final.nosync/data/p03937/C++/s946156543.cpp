#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
typedef pair<int, int> P;

void solve()
{
	int H, W;
	cin >> H >> W;
	int cnt = 0;
	vector< vector<char> > A(H, vector<char>(W));
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			cin >> A[i][j];
			if (A[i][j] == '#')
			{
				++cnt;
			}
		}
	}
	if (cnt != (H - 1) + (W - 1) + 1)
	{
		cout << "Impossible" << endl;
		return;
	}
	P pos;
	pos.first = 0;
	pos.second = 0;
	for (int i = 0; i < cnt - 1; ++i)
	{
		if (pos.first + 1 < H && A[pos.first + 1][pos.second] == '#')
		{
			pos.first = pos.first + 1;
		}
		else if (pos.second + 1 < W && A[pos.first][pos.second + 1] == '#')
		{
			pos.second = pos.second + 1;
		}
		else
		{
			cout << "Impossible" << endl;
			return;
		}
	}
	cout << "Possible" << endl;
}

int main()
{
	solve();
	return(0);
}