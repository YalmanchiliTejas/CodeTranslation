#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair
#define F first
#define S second
#define PB push_back
#define dump(x)  cout << #x << " = " << (x) << endl;	// debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, left, right)  (a).begin()+(left),(a).begin()+(right)	// left to (right-1)


int main() {
	int h, w;
	cin >> h >> w;
	vector<string> grid;
	FOR(i, 0, h-1) {
		string s;
		cin >> s;
		grid.push_back(s);
	}
	while (1) {
		bool oped1=false;
		bool oped2=false;

		set<int> delset = {};
		FOR(i, 0, h - 1) {
			bool isyoko = true;
			oped1 = false;
			FOR(j, 0, w - 1) {
				if (grid[i][j] == '#') {
					isyoko = false;
				}
			}
			if (isyoko) {
				oped1 = true;
				delset.insert(i);
			}
		}
		vector<string>ngrid;
		FOR(i,0,h-1) {
			if (delset.count(i)) {
				continue;
			}
			else {
				ngrid.PB(grid[i]);
			}
		}
		h -= delset.size();
		grid = ngrid;


		delset = {};
		ngrid = {};
		FOR(j, 0, w - 1) {
			bool istate = true;
			oped2 = false;
			FOR(i, 0, h - 1) {
				if (grid[i][j] == '#') {
					istate = false;
				}
			}
			if (istate) {
				oped2 = true;
				delset.insert(j);
			}
		}
		FOR(i, 0, h - 1) {
			string tmp;
			FOR(j, 0, w - 1) {
				if (delset.count(j)) {
					continue;
				}
				else {
					tmp.PB(grid[i][j]);
				}
			}
			ngrid.PB(tmp);
		}
		w -= delset.size();
		grid = ngrid;


		if (oped1 || oped2) {
			continue;
		}
		else {
			break;
		}
	}

	FOR(i, 0, h - 1) {
		cout << grid[i] << endl;
	}
	
	return 0;
}