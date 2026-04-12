#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;


void solve(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll suff[n];
	suff[n-1]=a[n-1];
	for(ll i=n-2;i>=0;i--){
		suff[i]=(suff[i+1]+a[i])%mod;
	}
	ll ans=0;
	for(ll i=0;i<n-1;i++){
		ll x=suff[i+1];
		ll y=a[i];
		ans=(ans+(x*y)%mod)%mod;
	}
	cout<<ans<<endl;
}


int main(){
	ll t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}
