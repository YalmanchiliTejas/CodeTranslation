#include <bits/stdc++.h>
using namespace std;

int main() {
	uint32_t N;
	cin >> N;
	
	vector<uint32_t>a(N);
	for(uint32_t i=0; i<N; i++) cin >> a[i];
	
	vector<int64_t> dp(N);
	copy(a.begin(), a.end(), dp.begin());
	
	for(uint32_t i=1; i<N; i++) {
		for(uint32_t j=0; i+j<N; j++) {
			if(i & 1) { // odd turn = Y - X;
				dp[j] = min(dp[j] - a[j+i], dp[j+1] - a[j]);
			} else { // even turn = X - Y;
				dp[j] = max(dp[j] + a[j+i], dp[j+1] + a[j]);	
			}
			//cout << dp[j] << " ";
		}
		//cout << endl;
	}
	
	if(N & 1) {
		cout << dp[0];
	} else {
		cout << -dp[0];
	}
	
	return 0;
}