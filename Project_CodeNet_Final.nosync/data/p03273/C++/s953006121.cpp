#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int H,W;
	array<array<int,100>,100> a;
	for (int i=0; i<100; i++) {
		for (int j=0; j<100; j++) {
			a[i][j]='.';
		}
	}
	cin >> H >> W;
	vector<int> hr,wr;

	for (int i=0; i<H; i++) {
		bool flg = true;
		for (int j=0; j<W; j++) {
			char tmp;
			cin >> tmp;
			if (tmp=='#') flg = false;
			a[i][j] = tmp;
		}
		if (flg) hr.push_back(i);
	}
	for (int j=0; j<W; j++) {
		bool flg = true;
		for (int i=0; i<H; i++) {
			if (a[i][j]=='#') flg = false;
		}
		if (flg) wr.push_back(j);
	}
	for (int i=0; i<H; i++) {
		if (find(hr.begin(), hr.end(), i)==hr.end()) {
			for (int j=0; j<W; j++) {
				if (find(wr.begin(), wr.end(), j)==wr.end()) {
					cout << (char)a[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}

