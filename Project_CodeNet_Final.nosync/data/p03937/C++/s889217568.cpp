#include <iostream>

using namespace std;

int main(void) {
	int H,W;
	cin >> H >> W;

	char c;
	int count = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> c;
			if (c == '#') {
				++count;
			}
		}
	}

	if (count == H+W-1) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}
