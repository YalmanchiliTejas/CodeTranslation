#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ld=long double;

const int MOD=1e9+7;

ll power(ll a,ll b){
	ll res=1ll;
	while(b>0){
		if(b%2==1) res=(res*a)%MOD;
		a= (a*a)%MOD;
		b/=2;
	}
	return res;
}

ll divide(ll a,ll b){
	return a*power(b,MOD-2)%MOD;
}


void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){ 
		cin>>a[i];
	}
	ll e=0;
	ll ss=0;
	for(int i=0;i<n;i++){
		e= (e+a[i])%MOD;
		ss= (ss+power(a[i],2ll))%MOD; 
	}
	e=(e*e)%MOD;
	ll ans = ((e-ss)%MOD + MOD)%MOD;
	ans=divide(ans,2);
	cout<<ans%MOD<<'\n'; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
