#include <bits/stdc++.h>

using namespace std;

int main() {

	int h,w;
	cin >> h >> w;

	vector<string> bw(h, "");

	for (int i = 0; i < h; i++) {
			cin >> bw[i];
	}

	bool bwcheck = true;
	for (int i = 0; i < h; i++) {
		bwcheck = true;
		for (int j = 0; j < w; j++) {
			if (bw[i][j] == '#') {
				bwcheck = false;
				break;
			}
		}
		if (bwcheck == true) {
			for (int k = i; k < h-1; k++) {
				bw[k] = bw[k + 1];
			}
			i--;
			h--;
		}
	}

	for (int j = 0; j < w; j++) {
		bwcheck = true;
		for (int i = 0; i < h; i++) {
			if (bw[i][j] == '#') {
				bwcheck = false;
				break;
			}
		}
		if (bwcheck == true) {
			for (int i = 0; i < h; i++) {
				for (int k = j; k < w-1; k++) {
					bw[i][k] = bw[i][k + 1];
				}
				bw[i].pop_back();
			}
			j--;
			w--;
		}
	}

	for (int i = 0; i < h; i++) {
		cout << bw[i] << endl;
	}
}