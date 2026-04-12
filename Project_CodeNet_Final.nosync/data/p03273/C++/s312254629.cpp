#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
#include <map>
#include <climits>
#include <set>
#include <queue>

#define DEBUG(x) cout << "> " << #x << ": " << x << "\n";

using namespace std;

template <typename T>
std::ostream &operator <<(std::ostream &out, vector<T> &v) {

	for (typename vector<T>::size_type i = 0; i < v.size(); ++i)
		out << v[i] << " ";
	out << "\n";

    return out;

}

bool is_row_white(vector<char>& v) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] != '.')
			return false;
	}
	return true;
}

bool is_column_white(vector<vector<char>>& v, int col) {
	for (int i = 0; i < v.size(); ++i) {
		if (v[i][col] != '.')
			return false;
	}
	return true;
}

int main() {

	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int h, w;
	cin >> h >> w;

	vector<vector<char>> grid(h, vector<char>(w));
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> grid[i][j];
		}
	}

	vector<int> white_row_indices, white_col_indices;
	for (int i = 0; i < h; ++i) {
		if (is_row_white(grid[i])) {
			white_row_indices.push_back(i);
		}
	}

	for (int i = 0; i < w; ++i) {
		if (is_column_white(grid, i)) {
			white_col_indices.push_back(i);
		}
	}

	for (int i = 0; i < white_row_indices.size(); ++i) {
		for (int j = 0; j < w; ++j) {
			grid[white_row_indices[i]][j] = ' ';
		}
	}
	for (int i = 0; i < white_col_indices.size(); ++i) {
		for (int j = 0; j < h; ++j) {
			grid[j][white_col_indices[i]] = ' ';
		}
	}

	bool skip_line;
	for (int i = 0; i < h; ++i) {
		skip_line = false;
		for (int j = 0; j < w; ++j) {
			if (grid[i][j] != ' ') {
				cout << grid[i][j];
				skip_line = true;
			}
		}
		if (skip_line)
			cout << "\n";
	}

	return 0;

}