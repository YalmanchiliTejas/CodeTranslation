#include <queue>
#include <string>
#include <iostream>
using namespace std;
int bit_in[16][3][7][7], bit_out[16][3][7][7];
int main() {
	int N;
	cin >> N;
	vector<int> X(N), Y(N);
	for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
	vector<string> BV(4);
	cin >> BV[0] >> BV[1] >> BV[2] >> BV[3];
	string B = BV[0] + BV[1] + BV[2] + BV[3];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			char c = (j == 0 ? 'R' : (j == 1 ? 'G' : 'B'));
			for (int k = 0; k < 4 + X[i]; ++k) {
				for (int l = 0; l < 4 + Y[i]; ++l) {
					for (int p = 0; p < X[i]; ++p) {
						for (int q = 0; q < Y[i]; ++q) {
							int tx = k - p, ty = l - q;
							if (0 <= tx && tx < 4 && 0 <= ty && ty < 4) {
								if (B[tx * 4 + ty] == c) bit_in[i][j][k][l] |= 1 << (tx * 4 + ty);
								else bit_out[i][j][k][l] |= 1 << (tx * 4 + ty);
							}
						}
					}
				}
			}
		}
	}
	queue<int> que; que.push(0);
	vector<int> dist(1 << 16, -1); dist[0] = 0;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 3; ++j) {
				char c = (j == 0 ? 'R' : (j == 1 ? 'G' : 'B'));
				for (int k = 0; k < 4 + X[i]; ++k) {
					for (int l = 0; l < 4 + Y[i]; ++l) {
						int bit = u;
						bit |= bit_in[i][j][k][l];
						bit &= ~bit_out[i][j][k][l];
						if (dist[bit] == -1) {
							dist[bit] = dist[u] + 1;
							que.push(bit);
						}
					}
				}
			}
		}
	}
	cout << dist[(1 << 16) - 1] << endl;
	return 0;
}
