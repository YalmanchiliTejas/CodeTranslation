#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string>
#include <ctype.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;
constexpr ll INF = 1000000000;

using namespace std;
int main() {
	int h, w; cin >> h >> w;

	vector<string>a(h);
	rep(i, h)cin >> a[i];

	vector<bool> row(h, false);
	vector<bool> col(w, false);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				row[i] = true;
				col[j] = true;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		if (row[i]) {
			for (int j = 0;j < w; j++) {
				if (col[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
}
