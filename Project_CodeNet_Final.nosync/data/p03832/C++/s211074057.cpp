#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
#define ll long long 
ll mod = 1000000007;
ll n, a, b, c, d;
ll factorial[1005];
ll ifactorial[1005];
ll memo[1005][1005];


ll power(ll a, ll b){ //ok
	a %= mod;
	if (b == 0) return 1;
	if (b == 1) return a;
	ll half = power(a, b/2);
	half *= half;
	half %= mod;
	if (b % 2){
		half *= a;
	}
	return half % mod;
}

ll p(ll n, ll k){ //ok
	return (factorial[n]*ifactorial[n - k])%mod;
}

ll dp(ll index, ll siz){
	if (index == n) return 1;
	if (index > n) return 0;
	if (siz > b) return 0;
	if (memo[index][siz] != -1) return memo[index][siz];
	ll answer = 0;
	for (int i = c; i <= d; i++){
		if (i*siz > n - index) break;
		ll subans = p(n - index, i*siz)*power(ifactorial[siz], i);
		subans %= mod;
		subans *= ifactorial[i];
		subans %= mod;
		subans *= dp(index + i*siz, siz + 1);
		subans %= mod;
		answer += subans;
		answer %= mod;
		//cout << index << " " << siz << " " << answer << endl;
	}
	answer += dp(index, siz + 1);
	answer %= mod;
	return memo[index][siz] = answer;
}

int main(){
	memset(memo, -1, sizeof(memo));
	factorial[0] = 1;
	ifactorial[0] = 1;
	for (int i = 1; i < 1005; i++){
		factorial[i] = i*factorial[i - 1];
		factorial[i] %= mod;
		ifactorial[i] = power(factorial[i], mod - 2);
	}
	
	scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
	printf("%lld\n", dp(0, a));
}