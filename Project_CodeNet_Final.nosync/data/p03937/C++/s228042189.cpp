#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <map>
#include <list>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>

// #define cerr if(false)cerr
#define watch(x) cerr << "> " << #x << ": " << x << "\n";

using namespace std;

template <typename T>
std::ostream &operator <<(std::ostream &out, vector<T> &v) {
	for (typename vector<T>::size_type i = 0; i < v.size(); ++i)
		out << v[i] << " ";
	out << "\n";
    return out;
}
template <typename T, typename N>
std::ostream &operator <<(std::ostream &out, vector<pair<T, N> > &v) {
	for (size_t i = 0; i < v.size(); ++i)
		out << "(" << v[i].first << ", " << v[i].second << ") ";
	out << "\n";
    return out;
}
template <typename T>
std::ostream &operator <<(std::ostream &out, vector<vector<T> > &v) {
	for (size_t i = 0; i < v.size(); ++i) {
		for (size_t j = 0; j < v[i].size(); ++j) {
			out << v[i][j] << " ";
		}
		out << "\n";
	}
   	return out;
}

int main() {

	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int h, w;
	cin >> h >> w;

	vector<string> grid(h);
	for (int i = 0; i < h; ++i) {
		cin >> grid[i];
	}

	int i = 0, j = 0;
	grid[0][0] = 'O';
	while (i < h && j < w) {
		if (i + 1 < h && grid[i + 1][j] == '#') {
			grid[i + 1][j] = 'O';
			++i;
		}
		else if (j + 1 < w && grid[i][j + 1] == '#') {			
			grid[i][j + 1] = 'O';
			++j;
		} else {
			cout << "Impossible\n";
			return 0;
		}

		if (i == h - 1 && j == w - 1) {
			break;
		}
	}

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) { 
			if (grid[i][j] == '#') {
				cout << "Impossible\n";
				return 0;
			}
		}
	}

	cout << "Possible\n";

	return 0;

}