#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define Would
#define you
#define please

int main() {
	int H,W;
	string str;
	int a[101][101] = {};
	cin >> H >> W;

	int yoko[101] = {};
	int tate[101] = {};

	rep1(i, H) {
		cin >> str;
		rep1(ii, W) {
			if (str[ii - 1] == '#') {
				a[i][ii] = 1;
				yoko[i] += 1;
				tate[ii] += 1;
			}
		}
	}

	rep1(i, H) {
		rep1(ii, W) {
			if (yoko[i] != 0 && tate[ii] != 0) {
				if (a[i][ii] == 1) {
					cout << "#";
				}
				else {
					cout << ".";
				}
			}
		}
		if (yoko[i] != 0) cout << "\n";
	}

	Would you please return 0;
}