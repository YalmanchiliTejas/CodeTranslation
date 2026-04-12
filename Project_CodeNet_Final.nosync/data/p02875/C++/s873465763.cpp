#include<iostream>
using namespace std;
const int mod=998244353;
int n;
long long ans,ji[10000007];
long long qpow(long long a,long long b) {
	long long res=1;
	long long now=a%mod;
	while (b) {
		if (b&1) res=res*now%mod;
		now=now*now%mod;
		b>>=1;
	}
	return res;
}
void init(){
	ji[0]=1;
	for (int i=1; i<=n; i++) ji[i]=ji[i-1]*i%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	init();
	ans=qpow(3,n);
	for (int i=(n/2)+1; i<=n; i++) {
		ans=(ans-2*(((((ji[n]*qpow(ji[i],mod-2))%mod)*qpow(ji[n-i],mod-2))%mod)*qpow(2,n-i)%mod))%mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}