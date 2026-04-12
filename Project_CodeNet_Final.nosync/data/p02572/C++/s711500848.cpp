#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long 
#define endl "\n"
#define all(x) (x).begin(),(x).end()
const int MOD = 1e9+7;
const int mxN = 2e5+3;

int powmod(int x, int y){
	int res = 1;
	x %= MOD;
	while(y > 0){
		if(y&1)res = (res * x) % MOD;
		y = y>>1;
		x = (x * x) % MOD;
	}
	return res;
}

void solve(){
	int n;
	cin >> n;
	int a[n];
	int sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
	}
	sum %= MOD;
	sum = (sum * sum) % MOD;
	int in = 0;
	for(int i = 0; i < n; ++i){
		in += (a[i] * a[i]) % MOD;
		in %= MOD;
	}
	sum -= in;
	sum = (sum + MOD) % MOD;
	int ans = (sum * powmod(2, MOD - 2)) % MOD;
	cout << ans << endl;
}

int32_t main(){
	IO;
	
	int nT = 1;
	//cin >> nT;
	for(int i = 1; i <= nT; ++i)
		solve();
	return 0;
}
