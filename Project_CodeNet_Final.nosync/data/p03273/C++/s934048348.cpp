#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define chmax(a, b) a = max(a, b)
using namespace std;

int		main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int H, W;
	cin >> H >> W;
	vector<vector<char>> grid(H, vector<char>(W));
	rep(i, H) rep(j, W) cin >> grid.at(i).at(j);
	vector<int> skip_row, skip_col;
	rep(row, H) {
		if (count(grid.at(row).begin(), grid.at(row).end(), '#') == 0)
			skip_row.push_back(row);
	}
	bool skip;
	rep(col, W) {
		skip = true;
		rep(row, H) {
			if (grid.at(row).at(col) == '#') {
				skip = false;
				break;
			}
		}
		if (skip)
			skip_col.push_back(col);
	}
	bool new_line;
	rep(row, H) {
		new_line = true;
		rep(col, W) {
			if (count(skip_row.begin(), skip_row.end(), row)) {
				new_line = false;
				break;
			}
			if (count(skip_col.begin(), skip_col.end(), col))
				continue;
			cout << grid.at(row).at(col);
		}
		if (new_line)
			cout << "\n";
	}
}
