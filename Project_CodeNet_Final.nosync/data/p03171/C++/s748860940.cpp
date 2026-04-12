#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[3005];
ll dp[3005][3005];
ll rec(ll l,ll r,ll eo){
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	if(r == l){
		if(eo) return -a[l];
		else return a[l];
	}
	ll ans1 = rec(l + 1,r,1 - eo);
	ll ans2 = rec(l,r - 1,1 - eo);
	if(eo){
		ans2 = ans2 - a[r];
		ans1 = ans1 - a[l];
		dp[l][r] = min(ans1,ans2);
	}
	else{
		ans2 = ans2 + a[r];
		ans1 = ans1 + a[l];
		dp[l][r] = max(ans1,ans2);
	}
	return dp[l][r];	
}
int main(){
	cin >> n;
	for(ll i = 0;i < n;i++){
		cin >> a[i];
	}
	memset(dp,-1,sizeof(dp));
	cout << rec(0,n - 1,0) << "\n";
	return 0;
}