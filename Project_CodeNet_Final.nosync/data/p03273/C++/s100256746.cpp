#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


//ABC107_b
int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char> > table(H, vector<char>(W));
	rep(i, H) {
		rep(j, W) {
			cin >> table.at(i).at(j);
		}
	}

	bool h[110], w[110];
	rep(i, H) {
		bool flg = true;
		rep(j, W) {
			if (table.at(i).at(j) == '#') {
				flg = false;
				break;
			}
		}
		h[i] = flg;
	}
	rep(i, W) {
		bool flg = true;
		rep(j, H) {
			if (table.at(j).at(i) == '#') {
				flg = false;
				break;
			}
		}
		w[i] = flg;
	}

	rep(i, H) {
		if (h[i]) {
			continue;
		}
		else {
			rep(j, W) {
				if (!w[j]) {
					cout << table.at(i).at(j);
				}
			}
			cout << endl;
		}
	}
}