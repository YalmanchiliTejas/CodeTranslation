#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)

int H, W;
string field[8];

int main() {
	cin >> H >> W;
	for_(i,0,H) cin >> field[i];
	
	int cx = 0, cy = 0;
	field[0][0] = '.';
	while (1) {
		if (cy != H - 1 && field[cy + 1][cx] == '#') {
			field[cy + 1][cx] = '.';
			++cy;
		} else if (cx != W - 1 && field[cy][cx + 1] == '#') {
			field[cy][cx + 1] = '.';
			++cx;
		} else {
			break;
		}
	}
	
	bool isok = true;
	for_(i,0,H) isok &= (field[i].find("#") == field[i].npos);
	cout << (isok ? "Possible" : "Impossible") << endl;
}