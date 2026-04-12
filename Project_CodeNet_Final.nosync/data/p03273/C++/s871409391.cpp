#include <iostream>
#include <math.h> 
#include <string> 
#include <algorithm>
using namespace std;

int main() {

	int H, W; cin >> H >> W;

	char a[1000][1000]; for (int i = 1; i <= H; i++) { for (int j = 1; j <= W; j++) cin >> a[i][j]; }

	int noh[1000], now[1000];

	for (int i = 1; i <= H; i++) {//圧縮できる列の操作。
		noh[i] = 0;
		for (int j = 1; j <= W; j++) if (a[i][j] == '#') noh[i] = 1;
	}

	for (int i = 1; i <= W; i++) {//圧縮できる行の操作。
		now[i] = 0;
		for (int j = 1; j <= H; j++) if (a[j][i] == '#') now[i] = 1;
	}
	// a[i][j] は noh[i] == 0 または now[j] == 0で圧縮される。


	for (int i = 1; i <= H; i++) { 
		for (int j = 1; j <= W; j++) {

			if (noh[i] == 1 && now[j] == 1) cout << a[i][j]; 

		}
		if (noh[i] == 1) cout << endl;
	}

}