#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve(long long d, int x, vector<long long> &dp)
{
	if (d == 1) {
		for(int i = 0; i < dp.size() && i < x; i ++) dp[i] = 1;
		return;
	}
	vector<long long> A(dp.size());
	if (d & 1) {
		solve(d - 1, x, A);
		for(int i = 0; i < x; i ++){
			for(int j = 0; j + i < dp.size(); j ++){
				dp[i + j] += A[j]; 
				if (dp[i + j] >= mod) dp[i + j] -= mod;
			}
		}
	}
	else{
		solve(d >> 1, x , A);
		for(int i = 0; i < dp.size(); i ++){
			for(int j = 0; j + i < dp.size(); j ++){
				dp[i + j] += A[j] * A[i] % mod; 
				if (dp[i + j] >= mod) dp[i + j] -= mod;
			}
		}
	}
}

int main()
{
	int x, n;
	long long d;
	while(~scanf("%d%lld%d", &n, &d, &x)) {
		if (!n && !d && !x) break;
		vector<long long> dp(n + 1);
		solve(d, x, dp);
		printf("%lld\n", dp[n]);
	}
	return 0;
}