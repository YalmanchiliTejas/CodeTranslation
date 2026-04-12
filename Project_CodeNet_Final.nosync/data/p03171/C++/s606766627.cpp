#ifndef ONLINE_JUDGE
    #include "debug.cpp"
#endif

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ar array

const int mxN = 3001;
vector<vector<int>> dp(mxN,vector<int>(mxN,0));

void solve(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(auto& e : arr) cin >> e;
	// print x - y
	for(int l = n-1; l >= 0; --l){
		for(int r = 0;r < n; ++r){
			if(l == r){
				dp[l][r] = arr[l];
			}else{
				dp[l][r] = max(arr[l]-dp[l+1][r], arr[r]-dp[l][r-1]);
			}
		}
	}
	cout << dp[0][n-1] << "\n";
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

