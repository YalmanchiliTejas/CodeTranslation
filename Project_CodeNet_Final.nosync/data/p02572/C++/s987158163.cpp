#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[214514];
ll gya(ll n,ll p,ll m){
	ll b=1;
	while(p){
		if(p%2)b=(b*n)%m;
		n=(n*n)%m;
		p/=2;
	}
	return b;
}
int main(){
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	ll ans=0,mod=1e9+7,num=0;
	for(int i=0;i<n;i++){
		ans+=a[i];
		ans%=mod;
		num+=a[i]*a[i];
		num%=mod;
	}
	ans*=ans;
	ans%=mod;
	ans=(ans-num);
	ans+=mod;
	ans%=mod;
	ll x=gya(2,mod-2,mod);
	ans*=x;
	ans%=mod;
	cout<<ans;
	return 0;
}
