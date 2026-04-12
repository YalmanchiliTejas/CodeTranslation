#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1e9+7;

int main(){
	
	ll n;
	cin >> n;

	vector<ll> v(n);

	ll sum = 0, ans = 0;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		sum += v[i];
	} 


	for(int i = 0; i < n; i++){
		ans += ((sum - v[i])%mod * v[i]%mod)%mod; 
		sum -= v[i];
	}

	cout << ans%mod << "\n";
	
}