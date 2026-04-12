#ifndef ONLINE_JUDGE
    #include "debug.cpp"
#endif

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ar array



int func(vector<vector<int>>& dp,vector<int>& arr,int n, int l, int r){
	if(dp[l][r]) return dp[l][r];
	if(l > r) return 0;
	if(l == r) {
		dp[l][r] = arr[l];
		return dp[l][r];
	}
	dp[l][r] = arr[l] - func(dp,arr,n,l+1,r);
	dp[l][r] = max(dp[l][r], arr[r] - func(dp,arr,n,l,r-1));
	return dp[l][r];
}

void solve(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(auto& e : arr) cin >> e;
	// print x - y
	vector<vector<int>> dp(n,vector<int>(n,0));
	cout << func(dp,arr,n,0, n-1) << "\n";	
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int TC = 1;
    while(TC--)
        solve();

    return 0;
}

