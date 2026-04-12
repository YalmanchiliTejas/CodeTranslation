#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[5000],dp[5000][5000],pref[5000];

ll sum(ll l, ll r){
	return pref[r] - pref[l - 1];
}

ll deq(ll l, ll r){
	if(l == r) return arr[l];
	if(dp[l][r] != -1) return dp[l][r];
	
	dp[l][r] = max((arr[l] + sum(l + 1, r) - deq(l + 1,r)), (arr[r] + sum(l, r - 1) - deq(l,r - 1)));
	
	return dp[l][r];
}

int main (){
	memset(dp,-1,sizeof dp);
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	pref[1] = arr[1];
	for(int i = 2; i <= n; i++){
		pref[i] = pref[i - 1] + arr[i];
	}
	
	ll ans = deq(1,n);
	ll totj = pref[n] - ans;
	cout << ans  - totj << endl; 
}