#include <bits/stdc++.h>
using namespace std;

int main() {
	uint32_t N;
	cin >> N;
	
	vector<uint32_t>a(N);
	for(uint32_t i=0; i<N; i++) cin >> a[i];
	
	vector<vector<int64_t>> dp(2, vector<int64_t>(N));
	copy(a.begin(), a.end(), dp[0].begin());
	
	for(uint32_t i=1; i<N; i++) {
		bool ic = i & 1;
		bool ip = (i - 1) & 1;
		
		for(uint32_t j=0; i+j<N; j++) {
			
			if(ic) { // odd turn = Y - X;
				dp[ic][j] = min(dp[ip][j] - a[j+i], dp[ip][j+1] - a[j]);
			} else { // even turn = X - Y;
				dp[ic][j] = max(dp[ip][j] + a[j+i], dp[ip][j+1] + a[j]);	
			}
			//cout << dp[ic][j] << " ";
		}
		//cout << endl;
	}
	
	if(N & 1) {
		cout << dp[0][0];
	} else {
		cout << -dp[1][0];
	}
	
	return 0;
}