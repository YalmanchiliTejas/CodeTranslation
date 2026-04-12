#include "bits/stdc++.h"

using ll = long long;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define all(c) begin(c), end(c)

using namespace std;
//#define DEBUG

void run() {
	int h, w;
	cin >> h >> w;
	vector<string> a(h, "");
	rep(i, h) {
		cin >> a[i];
	}
	if(a[h-1][w-1] == '.') {
		cout << "Impossible" << endl;
		return;
	}

	int x = h - 1, y = w - 1;
	for(;;) {
		if(x==0 && y==0 && a[x][y] == '#') {
			cout << "Possible" << endl;
			return;
		}
		if(x > 0 && y > 0 && a[x][y-1] == '.' && a[x-1][y] == '.') {
			cout << "Impossible" << endl;
			return;
		}

		if(x > 0 && a[x-1][y] == '#') {
			rep(i, y) if(a[x][i] == '#') {
				cout << "Impossible" << endl;
				return;
			}
			x--;
			continue;
		}
		if(y > 0 && a[x][y-1] == '#') {
			rep(i, x) if(a[i][y] == '#') {
				cout << "Impossible" << endl;
				return;
			}
			y--;
			continue;
		}
	}
}

int main() {
#ifdef DEBUG
	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());
	rep(i, 4) {
		cout <<"--------------: i=" << i << endl;
		run();
	}
#else
	run();
#endif
	return 0;
}
