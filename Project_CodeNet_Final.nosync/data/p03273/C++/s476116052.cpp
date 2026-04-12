#include<iostream>
#include<vector>
using namespace std;

bool check(vector<vector<char>>a,int y,int x,int h,int w) {
	bool hor(true), ver(true);
	for (int i(0); i < h; i++) {
		if (a[i][x] == '#')ver=false;
	}
	for (int i(0); i < w; i++) {
		if (a[y][i] == '#')hor=false;
	}
	if (ver == true || hor == true)return true;
	else return false;
}

int main(void) {
	int h, w;
	cin >> h >> w;
	vector<vector<char>>a;
	for (int i(0); i < h; i++) {
		vector<char>b;
		for (int j(0); j < w; j++) {
			char tmp;
			cin >> tmp;
			b.push_back(tmp);
		}
		a.push_back(b);
	}
	for (int i(0); i < h; i++) {
		int cnt(0);
		for (int j(0); j < w; j++) {
			if (!(check(a, i, j, h, w))) {
				cout << a[i][j];
				cnt++;
			}
		}
		if (cnt>0)cout << endl;
	}
	return 0;
}