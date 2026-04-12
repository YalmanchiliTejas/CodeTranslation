#include<bits/stdc++.h>
using namespace std; 
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
 
typedef long long int ll; 
typedef long double ld; 

ll mod = 1e9+7;

ll add(ll a, ll b){
	a = a%mod;
	b = b%mod;
	return (mod+(a+b)%mod)%mod;
}

ll mul(ll a, ll b){
	a = a%mod;
	b = b%mod;
	return (mod+(a*b)%mod)%mod;
}

int main(){
	
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin>>n;
	
	ll arr[n];
	ll su = 0;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		su += arr[i];
	}
	ll ans = 0;
	for(ll i=0;i<n;i++){
		su-=arr[i];
		ans = add(ans, mul(arr[i], su));
	}	
	cout<<ans<<endl;
}
