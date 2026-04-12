#include <bits/stdc++.h>
using namespace std;

int main() {
	int h,w;
	string raw;
	cin >> h >> w;
	int hh = h, ww = w;
	vector<vector<char>> masu(h, vector<char>(w));
	for (int i=0; i<h; i++) {
		cin >> raw;
		for (int j=0; j<w; j++) masu.at(i).at(j) = raw.at(j);
	}
	while (true) {
		int check=0;
		for (int i=0; i<h; i++) {
			int same=0;
			for (int j=0; j<w; j++) {
				if (masu.at(i).at(j) == '.') same++;
			}
			if (same == ww) {
				check++;
				hh--;
				for (int j=0; j<w; j++) masu.at(i).at(j) = ' ';
			}
		}
		for (int i=0; i<w; i++) {
			int same=0;
			char ch = masu.at(0).at(i);
			for (int j=0; j<h; j++) {
				if (masu.at(j).at(i) == '.') same++;
			}
			if (same == hh) {
				check++;
				ww--;
				for (int j=0; j<h; j++) masu.at(j).at(i) = ' ';
			}
		}
		if (check == 0) break;
	}
	for (int i=0; i<h; i++) {
		int count=0;
		for (int j=0; j<w; j++) {
			if (masu.at(i).at(j) == ' ') count++;
			else cout << masu.at(i).at(j);
		}
		if (count != w) cout << endl;
	}
	return 0;
}

