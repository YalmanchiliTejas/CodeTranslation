#include <bits/stdc++.h>
using namespace std;

int main()
{
	int H, W;
	bool f, res = true;
	int tmp = 0, g;
	cin >> H >> W;
	vector<vector<char>> A(H, vector<char>(W));
	for (int i = 0; i < H;i++) {
		f = true, g = -1;
		for (int j = 0; j < W;j++) {
			cin >> A[i][j];
			if (A[i][j] == '#') {
				if (g == 1)
					res = false;
				else
					g = 0;
				if (f) {
					if (tmp > j)
						res = false;
					else
						tmp = j;
				}
				else {
					res = false;
				}
			}
			else {
				if (g == 0) {
					f = false;
					g = 1;
				}
			}
		}
	}
	cout << (res ? "Possible" : "Impossible") << endl;
	return 0;
}
