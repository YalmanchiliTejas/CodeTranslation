#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353,N=1e7+5;
int fac[N],inv[N],pw2[N];
int ksm(int b,int n){
	int res=1;
	while(n){
		if(n&1) res=res*b%mod;
		b=b*b%mod; n>>=1;
	}
	return res;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)
		inv[i]=inv[i+1]*(i+1)%mod;
	pw2[0]=1;
	for(int i=1;i<=n;++i)
		pw2[i]=pw2[i-1]*2%mod;
} 
int C(int n,int m){
	if(n<m) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
void add(int &x,int y){
	x=(x+y)%mod;
}
signed main(){
	int n,ans=0;
	cin>>n;
	init(n);
	for(int i=n/2+1;i<=n;++i)
		add(ans,2*C(n,i)*pw2[n-i]%mod);
	int res=1;
	for(int i=1;i<=n;++i)
		res=res*3%mod;
	add(res,(mod-ans)%mod);
	cout<<res;
	return 0;
}