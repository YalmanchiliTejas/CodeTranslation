/* 
	Author: ankrypt
*/


#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int

ll N;
ll arr[3005];
ll dp[3005][3005][2];

ll rec(int beg, int end, int ctr) {
	if(beg > end) {
		return 0;
	}
	ll &ans = dp[beg][end][ctr];
	if(ans != -1) {
		return ans;
	}
	if(ctr == 0) {
		ans = max(arr[beg] + rec(beg + 1, end, 1), arr[end] + rec(beg, end - 1, 1));
	}
	else {
		ans = min(-arr[beg] + rec(beg + 1, end, 0), -arr[end] + rec(beg, end - 1, 0));
	}
	return ans;
}


int main() {
	scanf("%lld", &N);
	// cout << N <<  " " << -N;
	for(int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}
	memset(dp, -1, sizeof(dp));
	cout << rec(0, N - 1, 0);
	return 0;
}
/*
	Powered by Buggy Plugin
*/
