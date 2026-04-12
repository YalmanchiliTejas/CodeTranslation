#include "bits/stdc++.h"
using namespace std;


int main() {
	int N;
	cin >> N;
	vector<long long> A(N);
	for (int n = 0;n<N;++n) {
		cin >> A[n];
	}
	vector<vector<long long>> DP(N, vector<long long >(2, -1e18));
	// i 番目までからj個を選んだ
	// jの範囲は i/2 -1 から(i+1)/2)
	for (int i = 1; i <= N; ++i) {
		for (int j = (i + 1) / 2; j >= i / 2 - 1; --j) {
			if (j < 0) {
				continue;
			}
			DP[j][0] = max(DP[j][0] ,DP[j][1]); 
			if (j>0) {
				if (-1e18 != DP[j - 1][0]) {
					DP[j][1] = DP[j - 1][0] + A[i-1];
				}
				else {
					DP[j][1] = A[i-1];
				}
			}
		}
	}
	long long ans = 0;
	ans = max(DP[N/2][0], DP[N/2][1]);
	cout << ans << endl;
	return 0;
}

