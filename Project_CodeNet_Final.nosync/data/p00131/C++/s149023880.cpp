#include<iostream>
using namespace std;
int x[12][12];
int T[12][12], V[12][12];
void compute(int X, int Y) {
	int dx[5] = { -1,0,0,0,1 }, dy[5] = { 0,-1,0,1,0 };
	for (int i = 0; i < 5; i++) { T[X + dx[i]][Y + dy[i]]++; T[X + dx[i]][Y + dy[i]] %= 2; }
}
int main() {
	int n; cin >> n;
	for (int h = 0; h < n; h++) {
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++)cin >> x[i][j];
		}

		for (int i = 0; i < (1 << 10); i++) {
			int bit[11]; for (int j = 0; j < 10; j++)bit[j + 1] = (i / (1 << j)) % 2;
			for (int j = 0; j < 12; j++) {
				for (int k = 0; k < 12; k++) { T[j][k] = 0; V[j][k] = 0; }
			}

			for (int j = 1; j <= 10; j++) {
				if (bit[j] == 1) {
					compute(1, j);
					V[1][j] = 1;
				}
			}
			for (int j = 2; j <= 10; j++) {
				for (int k = 1; k <= 10; k++) {
					if (T[j - 1][k] != x[j - 1][k]) {
						compute(j, k);
						V[j][k] = 1;
					}
				}
			}
			bool OK = true; for (int k = 1; k <= 10; k++) { if (T[10][k] != x[10][k])OK = false; }
			if (OK == true) {
				for (int j = 1; j <= 10; j++) {
					for (int k = 1; k <= 10; k++) {
						if (k >= 2)cout << ' '; cout << V[j][k];
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}