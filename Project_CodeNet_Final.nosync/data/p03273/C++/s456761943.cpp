#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(ll i = 0; i < n; i++)

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> grid(h);
	rep(i, h) cin >> grid[i];
	map<int, bool> hight;
	rep(i, h) {
		bool flag = true;
		rep(j, w) {
			if (grid[i][j] == '#') flag = false;
		}
		if (flag) {
			hight[i] = true;
		}
	}
	map<int,bool> width;
	rep(j, w) {
		bool flag = true;
		rep(i, h) {
			if (grid[i][j] == '#') flag = false;
		}
		if (flag) {
			width[j] = true;
		}
	}
	rep(i, h) {
		rep(j, w) {
			if (hight[i] || width[j]) continue;
			cout << grid[i][j];
		}
		if(!hight[i]) cout << endl;
	}
	return 0;
}