#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)

int H, W;
string grid[8];

bool check() {
	for_(y,0,H) for_(x,0,W) if (grid[y][x] == '#') return false;
	return true;
}

bool rec(int x, int y) {
	if ((x == W-1 || grid[y][x+1] == '.') &&
		(y == H-1 || grid[y+1][x] == '.')) {
		return check();
	}
	
	bool res = false;
	if (x < W-1 && grid[y][x+1] == '#') {
		grid[y][x+1] = '.';
		res |= rec(x+1, y);
		grid[y][x+1] = '#';
	}
	
	if (y < H-1 && grid[y+1][x] == '#') {
		grid[y+1][x] = '.';
		res |= rec(x, y+1);
		grid[y+1][x] = '#';
	}
	
	return res;
}

int main() {
	cin >> H >> W;
	for_(i,0,H) cin >> grid[i];
	grid[0][0] = '.';
	puts(rec(0,0) ? "Possible" : "Impossible");
}