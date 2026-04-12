#include <iostream>
#include <vector>
using namespace std;

const char SPACE = 'C';

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> map(H);
	for (int i = 0; i < H; i++)
		cin >> map[i];

	for (int i = 0; i < H; i++) {
		bool flag = true; 
		for (int j = 0; j < W; j++) {
			if (map[i][j] == '#') {
				flag = false;
				break;
			}
		}
		if (flag)
			for (int j = 0; j < W; j++)
				map[i][j] = SPACE;
	}

	for (int i = 0; i < W; i++) {
		bool flag = true;
		for (int j = 0; j < H; j++) {
			if (map[j][i] == '#') {
				flag = false;
				break;
			}
		}
		if (flag)
			for (int j = 0; j < H; j++)
				map[j][i] = SPACE;
	}
	for (int i = 0; i < H; i++) {
		bool f = true;
		for (int j = 0; j < W; j++) {
			if (map[i][j] != SPACE) {
				cout << map[i][j];
				f = false;
			}
		}
		if (!f)
			cout << endl;
	}
		

}
