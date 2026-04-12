#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
using namespace std;
int a[100000], b[100000];
long long ans[100000] = {0}, ans1 = 0;
int main() {
	int h, w;
	int co = 0, co1 = 0, h1 = 0, w1 = 0;
	cin >> h >> w;
	char a[8][8];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				co++;
			}
		}
	}
	for (;;) {
		if (h1 == h - 1 && w1 == w - 1) {
			break;
		}
		if (a[h1][w1 + 1] == '#') {
			co1++;
			w1++;
			continue;
		}
		else if (a[h1 + 1][w1] == '#') {
			co1++;
			h1++;
			continue;
		}
		else {
			cout << "Impossible" << endl;
			return 0;
		}
	}
	if (co1 + 1 == co) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}