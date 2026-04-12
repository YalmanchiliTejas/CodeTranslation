#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
using ll = long long;
const ll MOD = 1000000007;

ll ddp[2][2][5][101];
//そこまでに0でないのは出たか、小さいことは確定しているか、0は何個か、何番目の文字か

int main() {
	string S;
	cin >> S;
	int K, N = S.size();
	cin >> K;

	ddp[0][0][0][0] = 1;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < 2;j++) {
			for (int k = 0;k < 2;k++) {
				for (int l = 0;l < 4;l++) {
					if (k) {
						for (int d = 0;d < 10;d++) {
							ddp[j || d > 0][k][l + (d != 0)][i + 1] += ddp[j][k][l][i];
						}
					}
					else {
						for (int d = 0;d <= (int)S[i] - 48;d++) {
							ddp[j || d > 0][d < (int)S[i] - 48][l + (d != 0)][i + 1] += ddp[j][k][l][i];
						}
					}
				}
			}
		}
	}
	cout << ddp[1][0][K][N] + ddp[1][1][K][N] << endl;
}