#include <iostream>
#include <vector>
using namespace std;
int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> Map(H + 1, vector<char>(W + 1));
	for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> Map[i][j];
	for (int i = 0; i < H; i++) Map[i][W] = '.';
	for (int i = 0; i < W; i++) Map[H][i] = '.';
	int y = 0, x = 0;
	if (Map[H - 2][W - 1] == '#' && Map[H - 1][W - 2] == '#') {
		cout << "Impossible" << endl;
		return 0;
	}
	bool ans = true;
	while (y != H - 1 || x != W - 1) {
		if ((Map[y][x + 1] == '#' && Map[y + 1][x] == '#') ||
			(Map[y][x + 1] == '.' && Map[y + 1][x] == '.') ||
			(x > 0 && y > 0 && Map[y][x - 1] == '#' && Map[y - 1][x] == '#')) {
			ans = false;
			break;
		}
		if (Map[y][x + 1] == '#') x++;
		else y++;
	}
	cout << (ans ? "Possible" : "Impossible") << endl;
}
