#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main(){
	

	int n;
	cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	ll sum = 0;
	std::vector<ll> pre(n);
	pre[0] = v[0];
	for(int i = 1; i < n; ++i){
		pre[i] = (pre[i-1]%mod+v[i]%mod)%mod;
	}
	// cout << pre[0]<< pre[1] << pre[2];
	for(int i = 0; i < n; ++i){
		sum = (sum % mod + (((pre[n-1]-pre[i] + mod)%mod ) * v[i]%mod))%mod;
	}
	cout << sum ;
	return 0;
}