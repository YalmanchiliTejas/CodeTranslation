#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, sum = 0;
	cin >> N;
	vector<long long> v(N);
	for(auto &i : v) cin >> i;
	for(auto &i : v) sum += i;

	vector<vector<long long>> dp(N, vector<long long>(N));

	for(int sz=0; sz<N; sz++){
		for(int i=0, j=sz; j<N; j++, i++){
			if(i == j) dp[i][j] = v[i];
			else if(i+1 == j) dp[i][j] = max(v[i], v[j]);
			else dp[i][j] = max(
			   	 v[j] + min(dp[i][j-2], dp[i+1][j-1]),
			    	 v[i] + min(dp[i+2][j], dp[i+1][j-1])
         		);
		}
	}
	long long a = dp[0][N-1];
	long long b = sum - a;
	cout << a - b;
}
