#include <iostream>
#include <string>
using namespace std;

int main() {
	int H, W, count = 0;
	bool A[8][8] = { "." }, check = true;
	string a;
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> a;
		for (int j = 0; j < W; j++) {
			if (a[j] == '#') A[i][j] = true, count++;
			else A[i][j] = false;
		}
	}
	for (int i = 0, j = 0; i < H && j < W;) {
		if (i == H - 1 && j == W - 1) break;
		if (A[i + 1][j]) i++, count--;
		else if (A[i][j + 1]) j++, count--;
		else { 
			check = false; 
			break;
		}
	}
	if (count > 1) check = false;
	if (check) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}