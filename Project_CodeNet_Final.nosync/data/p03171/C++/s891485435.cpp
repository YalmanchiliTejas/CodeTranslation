#ifndef ONLINE_JUDGE
    #include "debug.cpp"
#endif

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ar array

const int mxN = 3005;
vector<int> arr(mxN);
int n;
vector<vector<int>> dp(mxN,vector<int>(mxN,-1));

int func(int l, int r){
	if(dp[l][r]!=-1) return dp[l][r];
	if(l > r) return 0;
	if(l == r) {
		return arr[l];
	}
	int ans = arr[l] - func(l+1,r);
	ans = max(ans, arr[r] - func(l,r-1));
	dp[l][r] = ans;
	return ans;
}

void solve(){
	cin >> n;
	for(int i = 0;i < n; i++) cin >> arr[i];
	cout << func(0, n-1) << "\n";	
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

