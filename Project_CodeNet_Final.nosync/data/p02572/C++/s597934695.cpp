#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ll mod = 1000000000+7;
	ll n; cin>>n; ll arr[n];
	for(int i = 0; i < n; i++) cin>>arr[i];
	ll sup[n];
	for(int i = n-1; i >= 0; i--){
		if(i == n-1) sup[i] = arr[n-1];
		else sup[i] = ((sup[i+1]%mod)+(arr[i]%mod))%mod;
	}
	ll ans = 0;
	for(int i = 0; i < n-1; i++){
		ans += ((arr[i]%mod) * (sup[i+1]%mod))%mod; 
		ans %= mod;
	}
	cout<<ans%mod<<"\n";
}