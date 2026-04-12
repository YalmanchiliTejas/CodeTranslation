#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9+100;
const int MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++){
		cin>>nums[i];
	}
	ll p = 0;
	ll ans = 0;
	for (int i = n-1; i >= 0; i--){
		ans += (nums[i] * p) % MOD; ans %= MOD;
		p += nums[i]; p %= MOD;
	}
	cout<<ans<<'\n';
	return 0;
}