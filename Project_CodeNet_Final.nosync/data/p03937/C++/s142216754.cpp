#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solve(int H, int W, const vector<string> &A)
{
	int n = 0;
	for (auto &s : A) {
		for (auto c : s) {
			if (c == '#') {
				++n;
			}
		}
	}
	int x = 0, y = 0;
	int m = 1;
	if (A[y][x] != '#') {
		return false;
	}
	while (x + 1 < W || y + 1 < H) {
		if (x + 1 < W && A[y][x + 1] == '#') {
			++x;
			++m;
		}
		else if (y + 1 < H && A[y + 1][x] == '#') {
			++y;
			++m;
		}
		else {
			return false;
		}
	}
	return n == m;
}

int main()
{
	int H, W;
	cin >> H >> W;
	vector<string> A(H);
	for (auto &s : A) {
		cin >> s;
	}
	if (solve(H, W, A)) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
}