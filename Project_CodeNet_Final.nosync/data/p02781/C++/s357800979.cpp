#include "bits/stdc++.h"
using namespace std;

int main() {
	string N;
	cin >> N;
	int K;
	cin >> K;
	vector<vector<int>> DP0(K + 1, vector<int>(N.size())); 
	vector<vector<int>> DP1(K + 1, vector<int>(N.size()));
	DP0[0][0] = 1; 
	DP0[1][0] = (N[0] - '0') -1;
	DP1[1][0] = 1;
	
	for (int n = 0; n < N.size()-1;++n) {
		//
		for (int m = 0;m <= K;++m) {
			DP0[m][n + 1] += DP0[m][n];
			if (m + 1 <= K) {
				DP0[m + 1][n + 1] += 9 * DP0[m][n];
			}
		}
		//
		for (int m = 0; m <= K; ++m) {
			if (0 == (N[n + 1] - '0')) {
				DP1[m][n + 1] += DP1[m][n];
			}
			else {
				DP0[m][n + 1] += DP1[m][n];
				if (m + 1 <= K) {
					DP0[m + 1][n + 1] += (N[n + 1] - '0' - 1) * DP1[m][n];
					DP1[m + 1][n + 1] += DP1[m][n];
				}
			}
		}
	}
	cout << DP0[K][N.size() - 1] +DP1[K][N.size()-1]<< endl;
	return 0;
}