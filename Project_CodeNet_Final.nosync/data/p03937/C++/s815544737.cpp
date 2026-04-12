#include<bits/stdc++.h>
using namespace std;
const long long INF = 10000000000;
int main() {
	int H, W; cin >> H >> W;
	char A[H][W];
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> A[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (A[i][j] == '#') cnt++;
		}
	}
	if (cnt == H + W - 1) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}