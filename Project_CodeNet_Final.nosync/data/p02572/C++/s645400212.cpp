#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod ((ll)(1e9) + 7LL)

int main(){
	ll n;
	cin >> n;
	ll ar[n],prefix[n];
	for(ll i = 0;i < n;i++){
		cin >> ar[i];
		prefix[i] = ar[i];
	}
	for(ll i = 1;i < n;i++){
		prefix[i] += prefix[i-1];
		prefix[i] %= mod;
	}
	ll ans = 0;
	for(ll i = 0;i < n-1;i++){
		ans += ((ar[i] % mod) * (prefix[n-1] - prefix[i] + mod)) % mod;
		ans %= mod;
	}
	cout<<ans;
}