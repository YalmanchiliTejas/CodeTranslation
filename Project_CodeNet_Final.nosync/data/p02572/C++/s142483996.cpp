#include<bits/stdc++.h>
#define ll long long
#define nes ios_base :: sync_with_stdio(0); cin.tie(0);
using namespace std;
const ll m=1e9+7;
ll mod(ll x){
	return ((x%m+m)%m);
}
ll add(ll a,ll b){
	return(mod(mod(a)+mod(b)));
}
ll mul(ll a,ll b){
	return (mod(mod(a)*mod(b)));
}
int main(){
	nes;
	ll n;
	cin>>n;
	vector<ll>v(n);
	ll sum=0,sum1=0,res=0;
	for(ll i=0;i<n;++i){
		cin>>v[i];
		sum=add(sum,v[i]);
	}
	for(ll i=0;i<n;++i){
		sum-=v[i];
		sum=mod(sum);
		res=add(res,mul(sum,v[i]));
	}
	cout<<res;
	return 0;
}