#include<iostream>
using namespace std;


int main(void){
	int H, W; cin >> H >> W;
	int i, j;
	char a[H][W];
	bool h[H] = {}, w[W] = {};

	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				h[i] = true;
				w[j] = true;
			}
		}
	}

	for (i = 0; i < H; i++) {
		if (h[i]) {
			for (j = 0; j < W; j++) {
				if (w[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}