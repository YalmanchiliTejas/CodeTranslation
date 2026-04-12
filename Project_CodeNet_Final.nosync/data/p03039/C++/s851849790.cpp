#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return res%mod;
}
int main(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll t=n*m,p=k,num=1;
	for(int i=1;i<=k;i++){
		num=(num%mod*t%mod*qpow(p,mod-2)%mod)%mod;
		t--,p--;
	}
	ll x=(k*(k-1))/2;
	cout<<(x%mod*(n+m)%mod*num%mod*qpow(3,mod-2)%mod)%mod<<endl;
}