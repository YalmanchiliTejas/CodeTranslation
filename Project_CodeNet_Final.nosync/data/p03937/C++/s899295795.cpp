#include "iostream"

using namespace std;

int H, W;
char map;
int num = 0;

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map;
			if (map == '#')num++;
		}
	}
	if (num == H + W - 1)cout << "Possible\n";
	else cout << "Impossible\n";
	return 0;
}