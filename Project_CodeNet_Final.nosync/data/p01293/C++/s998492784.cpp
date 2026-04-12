#include<iostream>
#include<string>
using namespace std;
char T[16] = "0123456789TJQKA";
char V[5] = "SHCD";
int P[4][13]; char E; string S;
int main() {
	while (true) {
		cin >> E; if (E == '#')break;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++)P[i][j] = 0;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				cin >> S;
				for (int k = 0; k < 15; k++) {
					if (S[0] == T[k])P[i][j] += k * 4;
				}
				for (int k = 0; k < 4; k++) {
					if (S[1] == V[k])P[i][j] += k;
				}
				if (S[1] == E)P[i][j] += 100;
			}
		}
		int N = 0, W = 0, M = 0;
		for (int i = 0; i < 13; i++) {
			int maxn = 0, maxid = 0;
			for (int j = 0; j < 4; j++) {
				if (maxn < P[j][i] && (P[j][i] % 4 == P[M][i] % 4 || P[j][i] >= 100)) {
					maxn = P[j][i]; maxid = j;
				}
			}
			M = maxid;
			if (maxid % 2 == 0)N++;
			else W++;
		}
		if (N > W)cout << "NS " << N - 6 << endl;
		else cout << "EW " << W - 6 << endl;
	}
	return 0;
}