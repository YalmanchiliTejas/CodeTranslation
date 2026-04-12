
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

//typedefリスト
typedef vector<int> vint;
typedef vector<string> vstr;

int main(void) {
	int H, W, jur, jurl,n;
	cin >> H >> W;
	n=0;
	vint del_side(H);
	vint del_leng(W);

	vstr a(H);
	//全部白の行を判定
	for (int i = 0; i < H; i++) {
		jur = 0;
		cin >> a[i];

		for (int j = 0; j < W; j++) {
			if (a[i][j] == '.')jur++;
		}
		if (jur == W)del_side[i] = 1;
		else del_side[i] = 0;

	}

	for (int k = 0; k < W; k++) {
		jurl = 0;

		for (int l = 0; l < H; l++) {

			if (a[l][k] == '.')jurl++;
		}

		if (jurl == H)del_leng[k] = 1;
		else del_leng[k] = 0;
		}

	for (int p = 0; p < W; p++) {
	 
		if (del_leng[p] == 1) {
			for (int o = 0; o < H; o++) {
				a[o].erase(a[o].begin() + (p-n));
				
			}
			n++;
		}
	}
	for (int m = 0; m < H; m++) {

		if (del_side[m] == 0)cout << a[m] << endl;

	}
	

}

