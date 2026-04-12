#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

long long int dp[105][12][2];

string S;

int K;

int C[150];

int main(void) {

	cin >> S;

	cin >> K;

	int M = S.size();

	for (int i = 0; i < M; i++) {
		C[M - i ] = S[i] - '0';
	 }

	/*for (int i = 1; i <= M; i++) {
		cout << C[i] << endl;
	}*/

	
		dp[M+1][0][0] = 1;
	

	for (int i = M + 1; i >= 1; i--) {
		for (int k = 0; k <= 8; k++) {
			for (int s = 0; s <= 1; s++) {
				int max_val;
				if (s == 1) { max_val = 9; }
				else { max_val = C[i]; }
				for (int m = 0; m <= max_val; m++) {
					int next_k = k;
					if (m != 0) { next_k++; }
					dp[i][next_k][s | (C[i] > m)] += dp[i + 1][k][s];
				}
			}
		}
	}

	/*for (int i = 3; i >= 1; i--) {
		for (int k = 0; k <= 3; k++) {
			for (int s = 0; s <= 1; s++) {
				cout << "dp[" << i << "][" << k << "][" << s << "]= " << dp[i][k][s] << endl;
			}
		}
	}*/

	cout << dp[1][K][0] + dp[1][K][1] << endl;


	return 0;
}