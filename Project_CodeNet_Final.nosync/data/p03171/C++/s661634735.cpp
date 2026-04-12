#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[3000];
vector<vector<ll>> dp(3000, vector<ll>(3000, -1));


ll fun(int l, int r){
	if(dp[l][r] != -1) return dp[l][r];
	if(l == r){
		return dp[l][l] = a[l];
	}
	return dp[l][r] = max(a[l] - fun(l+1, r),a[r] - fun(l, r-1));
}


int main(){
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	cout << fun(0, n-1);
}