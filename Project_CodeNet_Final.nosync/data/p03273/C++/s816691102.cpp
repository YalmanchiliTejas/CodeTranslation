#define REP(i, n) for(int i = 0; i < (int)(n); i++)

#include "bits/stdc++.h"
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> a(H, vector<char>(W));

	REP(h, H) {
		string S;
		cin >> S;
		REP(w, W) {
			a[h][w] = S[w];
		}
	}

	REP(h, H) {
		bool flag_del = true;
		REP(w, W) {
			if (a[h][w] == '#') {
				flag_del = false;
			}
		}
		if (flag_del) {
			REP(w, W) {
				a[h][w] = 'd';
			}
		}
	}

	REP(w, W) {
		bool flag_del = true;
		REP(h, H) {
			if (a[h][w] == '#') {
				flag_del = false;
			}
		}
		if (flag_del) {
			REP(h, H) {
				a[h][w] = 'd';
			}
		}
	}

	REP(h, H) {
		bool flag_disp = false;
		REP(w, W) {
			if (a[h][w] != 'd') {
				cout << a[h][w];
				flag_disp = true;
			}
		}
		if (flag_disp) {
			cout << endl;
		}		
	}

	return 0;
}
