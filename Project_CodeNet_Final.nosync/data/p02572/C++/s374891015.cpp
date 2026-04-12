//-----------------------
// author : xyqkoala
// time : 2020-08-29
//-----------------------

#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<algorithm>
#include<cmath>
#include<numeric>
using namespace std;

typedef long long LL;
const int MOD = 1e9+7;

void solve();


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}


void solve(){
	int n;cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++) cin>>nums[i];
	// LL sum = 0;
	// LL tcnt = 0;
	// for(auto item:nums){
	// 	sum = (sum+item)%MOD;
	// 	tcnt = (tcnt+((1ll*item*item)%MOD))%MOD;
	// }
	// sum = (1ll*sum*sum)%MOD;
	// LL res = sum-tcnt;
	// res = (res+MOD)%MOD;
	// res = res/2;
	// cout<<res<<endl;
	vector<LL> sif(n+1,0);
	for(int i=0;i<n;i++) sif[i+1] = sif[i]+nums[i];
	LL res = 0;
	for(int i=(n-2);i>=0;i--){
		LL temp = 1ll * (sif[n]-sif[i+1]);
		temp = temp%MOD;
		temp = (temp*nums[i])%MOD;
		res = (res+temp)%MOD;
	}
	cout<<res<<endl;
}

