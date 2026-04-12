#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int H, W; string s[9];
int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) cin >> s[i];
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (s[i][j] == '#') cnt++;
		}
	}
	cout << (cnt == H + W - 1 ? "Possible" : "Impossible") << endl;
	return 0;
}