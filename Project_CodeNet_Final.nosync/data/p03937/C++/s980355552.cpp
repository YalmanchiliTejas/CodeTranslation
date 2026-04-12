#include<iostream>
using namespace std;

int H, W;
char maze[10][10];

int main() {
	cin >> H >> W;
	int sum = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == '#')sum++;
		}
	}
	cout << (sum == H + W - 1 ? "Possible" : "Impossible") << endl;

	return 0;
}