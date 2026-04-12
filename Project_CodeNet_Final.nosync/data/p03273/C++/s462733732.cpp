#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int  h, w, iy[100], jx[100];
#define rep(i,n) for(int i =0;i < n;i++)
int main() {
	cin >> h >> w;vector<vector<char>> a(h, vector<char>(w));
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
		}
	}
	rep(i, h) {
		rep(j, w) {
			if (a[i][j] != '.') break;
			if (j == w - 1) {
				iy[i] = 1;
			}
		}
	}
	rep(i, w) {
		rep(j, h) {
			if (a[j][i] != '.') break;
			if (j == h - 1) {
				jx[i] = 1;
			}
		}
	}
	rep(i, h) {
		if (!iy[i]) {
			rep(j, w) {
				if (!jx[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
}