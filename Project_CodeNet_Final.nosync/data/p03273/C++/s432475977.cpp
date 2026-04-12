#include <iostream>
using namespace std;
char mark[102][102];
char tmp[102][102];

int main() {
	int H, W;cin >> H >> W;
	for (int i = 0;i < H;i++) {
		for (int k = 0;k < W;k++) {
			cin >> mark[i][k];
			tmp[i][k] = mark[i][k];
		}
	}

	for (int i = 0;i < H;i++) {
		bool Hflag = 1;
		for (int k = 0;k < W;k++) {
			if (mark[i][k] == '#') {
				Hflag = 0;
			}
		}

		if (Hflag) {
			for (int k = 0;k < W;k++) {
				tmp[i][k] = '0';
			}
		}
	}


	
	for (int k = 0;k < W;k++) {
		bool Kflag = 1;
		for (int i = 0;i < H;i++) {
			if (mark[i][k] == '#') {
				Kflag = 0;
			}
		}
		if (Kflag) {
			for (int i = 0;i < H;i++) {
				tmp[i][k] = '0';
			}
		}
	}

	for (int i = 0;i < H;i++) {
		bool enter = 0;
		for (int k = 0;k < W;k++) {
			if (tmp[i][k] != '0') {
				cout << mark[i][k];
				enter = 1;
			}
		}

		if (enter)cout << "\n";
	}

	return 0;
}
