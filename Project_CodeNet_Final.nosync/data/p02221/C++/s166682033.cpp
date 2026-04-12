#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	int X = 1 << N;
	string S;
	vector<vector<int> > P(N + 1, vector<int>(X));
	cin >> S;
	for (int i = 0; i < X; i++) cin >> P[0][i];
	for (int i = 0; i < N; i++) {
		int Y = 1 << i;
		for (int j = 0; j < X; j++) {
			int D = abs(P[i][j] - P[i][(j + Y) % X]);
			if (S[D - 1] == '0') P[i + 1][j] = min(P[i][j], P[i][(j + Y) % X]);
			else P[i + 1][j] = max(P[i][j], P[i][(j + Y) % X]);
		}
	}
	for (int i = 0; i < X; i++) {
		cout << P[N][i] << endl;
	}
}
