#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<queue>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool done[10][10];

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> board(H);
	for (int i = 0; i < H; i++)
		cin >> board[i];
	int y = 0, x = 0;
	while (1) {
		done[y][x] = true;
		if (y == H-1 && x == W-1) break;
		if (y+1 < H && board[y+1][x] == '#') {
			y = y+1;
			continue;
		}
		if (x+1 < W && board[y][x+1] == '#') {
			x = x+1;
			continue;
		}
		break;
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] == '#' && !done[i][j]) {
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;
	return 0;
}
