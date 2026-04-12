
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	string   c[1000];
	int side[1000][2];
	for (int i = 0; i < H; i++) {
		side[i][0] = 99999;
		side[i][1] = -1;
			cin >> c[i];
			for (int j = 0; j < W; j++) {
				if (c[i][j] == 'B') {
					side[i][0] = min(side[i][0], j);
					side[i][1] = max(side[i][1], j);
				}
			}
	}
	int answer = 0;
	for (int i = 0; i < H; i++) {
		for (int k = 0; k < H; k++) {
			if (side[i][0] != 99999 && side[k][1] != -1) {
			answer = max(answer, abs(i - k) + abs(side[i][0] - side[k][1]));
		}
	}
	}
	cout << answer << endl;

	return 0;
}

