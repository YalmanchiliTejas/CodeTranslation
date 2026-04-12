#include <iostream>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int i = 0; i < W; i++) {
			char c;
			cin >> c;
			if (c == '#') cnt++;
		}
	}
	if (cnt == (H + W - 1)) {
		cout << "Possible" << endl;
	} else {
		cout << "Impossible" << endl;
	}
}