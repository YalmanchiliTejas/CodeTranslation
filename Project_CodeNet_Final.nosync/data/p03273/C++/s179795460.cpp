#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
#define INF 1LL<<60
#define PI acos(-1)
typedef long long ll;
typedef pair<int, int> p_ii;

char grid[110][110];
int main() {
	
	set<int> c;
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < h; i++) {
		bool flag = true;
		if (!flag)continue;
		for (int j = 0; j < w; j++) {
			if (grid[i][j] == '#') {
				flag = false;
				break;
			}
		}
		if (flag) {
			c.insert(i);
			for (int j = 0; j < w; j++) {
				if (grid[i][j] == '.') {
					grid[i][j] = '*';
				}
			}
		}
	}
	for (int i = 0; i < w; i++) {
		bool flag = true;
		if (!flag)continue;
		for (int j = 0; j < h; j++) {
			if (grid[j][i] == '#') {
				flag = false;
				break;
			}
		}
		if (flag) {
			for (int j = 0; j < h; j++) {
				if (grid[j][i] == '.') {
					grid[j][i] = '*';
				}
			}
		}
	}

	for (int i = 0; i < h; i++){
		bool update = true;
		for (int j = 0; j < w; j++) {
			if (grid[i][j] != '*'){
				cout << grid[i][j];
			}
		}
		if(c.count(i)==0)cout << endl;
	}

	return 0;
}