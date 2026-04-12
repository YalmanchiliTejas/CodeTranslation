#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = (int)1e9 + 7;

ll mult(ll a, ll b){
	return ((ll)(a % MOD) * (b % MOD)) % MOD;
}

ll add(ll a, ll b){
	
	a = ((a % MOD) + (b % MOD)) % MOD;
	return a;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    ll pd = 0L;

    for(int i = 0; i < n; ++i){
    	cin >> a[i];
    }
    pd = a[n - 1];
    ll ans = 0L;
    for(int i = n - 2; i >= 0; --i){
    	ans = add(ans, mult(a[i], pd));
    	pd = add(a[i], pd);
    }   
    
    cout << ans;
    
	return 0;
}