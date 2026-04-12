#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
ll exp(ll taban, ll us) {
    ll carpan = taban % mod;
    ll temp = us;
    ll res = 1;
    while(temp){
        if(temp % 2) res = (res*carpan) % mod;
        temp /= 2;
        carpan = (carpan*carpan) % mod;
    }
    return res;
}
ll ebob(ll a, ll b){
	if(!a)return b;
	return ebob(b%a, a);
}
ll ekok(ll a, ll b){
	return (a*b)/ebob(a, b);
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, s; cin>>n>>s;
	vector<int> vec(n);
	ll dp[s+1] = {};
	ll ans = 0;
	for(int i = 0; i < n; i++){
		cin>>vec[i];
		dp[0]++;
		dp[0] %= 998244353;
		if(vec[i] <= s && dp[s - vec[i]]) ans = (ans + dp[s - vec[i]]*(n-i)) % 998244353;
		for(int j = s; j >= 0; j--){
			if(j + vec[i] <= s){
				dp[j + vec[i]] = (dp[j + vec[i]] + dp[j]) % 998244353;
			}
		}
	}
	cout<<ans<<endl;
}