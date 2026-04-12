#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iterator>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> a(H, vector<char>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> a[i][j];
		}
	}
	int dots_count;
	vector<int> rm_row(0), rm_column(0);
	for (int i = 0; i < H; i++) {
		dots_count = 0;
		for (int j = 0; j < W; j++) {
			if (a[i][j] == '.') {
				dots_count++;
			}
		}
		if (dots_count == W) {
			rm_row.push_back(i);
		}
	}
	for (int i = 0; i < W; i++) {
		dots_count = 0;
		for (int j = 0; j < H; j++) {
			if (a[j][i] == '.') {
				dots_count++;
			}
		}
		if (dots_count == H) {
			rm_column.push_back(i);
		}
	}
	for (int i = 0; i < H; i++) {
		if (find(rm_row.begin(), rm_row.end(), i) == rm_row.end()) {
			for (int j = 0; j < W; j++) {
				if (find(rm_column.begin(), rm_column.end(), j) == rm_column.end()) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}


	return 0;
}