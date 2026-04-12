//    _____ _     _                _           _     _ _     _     
//    \_   \ |_  (_)___  __      _| |__   __ _| |_  (_) |_  (_)___ 
//     / /\/ __| | / __| \ \ /\ / / '_ \ / _` | __| | | __| | / __|
//  /\/ /_ | |_  | \__ \  \ V  V /| | | | (_| | |_  | | |_  | \__ \
//  \____/  \__| |_|___/   \_/\_/ |_| |_|\__,_|\__| |_|\__| |_|___/
//                                                                 
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll div_floor(ll a, ll b) {
	// use when ret <= a/b, (a and b can be -ve)
	return a / b - (((a ^ b) < 0) and a % b);
}
ll div_ceil(ll a, ll b) { 
	// use when ret >= a/b, (a and b can be -ve)
	return a / b + (((a ^ b) >= 0) and a % b);
}
const int sz=1e3+9;
ll dp[sz][4][3];
string s;
int k;

ll solve(int idx,int rem,int can){
	ll &ret=dp[idx][rem][can];
	if(!idx) return ret=!rem;
	if(~ret) return ret;
	int val=s[idx]-'0';
	if(!rem) return ret=solve(idx-1,rem,can);
	ret=0;
	if(can) ret=9*solve(idx-1,rem-1,1)+solve(idx-1,rem,1);
	else{
		if(val) ret=solve(idx-1,rem-1,can);
		else ret=solve(idx-1,rem,can);
		for(int i=0;i<val;i++) ret+=solve(idx-1,rem-(i>0),can|1);
	}
	return ret;
}


int main(){
	cin>>s>>k;
	reverse(all(s));
	s="0"+s;
	memset(dp,-1,sizeof(dp));
	cout<<solve(s.size()-1,k,0);
	return 0;
}