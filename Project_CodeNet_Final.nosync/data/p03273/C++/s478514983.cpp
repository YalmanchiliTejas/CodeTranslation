#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <string>
#include<algorithm>
#include <vector>
#include <cassert>
#include<cmath>
using namespace std;
int main() {
	int i, j;
	int H, W;
	int flag = 0;//#があればフラグ1
	char a[101][101];
	char h[101][101];
	char w[101][101];
	int h_flag[101] = {};
	int w_flag[101] = {};
	int sum_h = 0;
	int sum_w = 0;

	cin >> H >> W;
	for (i = 0; i < H; ++i) {
		for (j = 0; j < W; ++j) {
			cin >> a[i][j];
		}
	}

	for (i = 0; i < H; ++i) {//#があるか見る(Height)
		for (j = 0; j < W; ++j) {
			if (a[i][j] == '#') {
				flag = 1;
			}
		}
		if (flag == 1) {
			h_flag[i] = 1;
		}
		flag = 0;
	}

	for (i = 0; i < H; ++i) {//フラグたてて出力
		if (h_flag[i] == 1) {
			for (j = 0; j < W; ++j) {
				h[i][j] = a[i][j];

			}
			sum_h += h_flag[i];
		}

	}
	//cout <<"sum_h "<< sum_h << endl;//デバッグ

	for (j = 0; j < W; ++j) {//#があるか見る(Weight)
		for (i = 0; i <H; ++i) {
			if (h[i][j] == '#') {
				flag = 1;
			}

		}
		if (flag == 1) {
			w_flag[j] = 1;
		}
		flag = 0;
		sum_w += w_flag[j];
	}
	//cout << "sum_w " << sum_w << endl;//デバッグ

	for (j = 0; j < W; ++j) {//フラグたてて出力
		if (w_flag[j] == 1) {
			for (i = 0; i < H; ++i) {
				w[i][j] = h[i][j];
			}
		}
	}




	//cout << endl;//デバッグ

	for (i = 0; i < H; ++i) {

		for (j = 0; j < W; ++j) {
			if (h_flag[i] == 1 && w_flag[j] == 1) {
				cout << w[i][j];
			}

		}
		if (h_flag[i] == 1) {
			cout << endl;
		}

	}

}