#include <bits/stdc++.h>

using namespace std;

#define Rep(i,a,b)  for (int i=(a);i<(b);i++)
#define rep(i,n)    for (int i=0;i<(n);i++)
#define all(x)      (x).begin(), (x).end()

#define ll long long

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> grid(h);
	rep (i, h)
		cin >> grid[i];

	for (int i = h - 1; i >= 0; i--) {
		auto res = find_if(all(grid[i]), [](char c) { return c == '#'; });
		if (res == grid[i].end()) {
			grid.erase(grid.begin() + i);
			h--;
		}
	}

	for (int i = w - 1; i >= 0; i--) {
		bool flag = true;
		rep (j, h) {
			if (grid[j][i] == '#') {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			rep (j, h)
				grid[j].erase(grid[j].begin() + i);
		}
	}

	rep (i, h)
		cout << grid[i] << endl;
}

