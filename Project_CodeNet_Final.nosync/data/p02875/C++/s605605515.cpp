#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 10000100
const int mod=998244353;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int fac[N],inv[N],n,ans,pw2[N];
inline int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	inv[n]=qpow(fac[n],mod-2)%mod;
	for(int i=n-1;i>=0;--i){
		inv[i]=1LL*inv[i+1]*(i+1)%mod;
	}
}
inline int C(int n,int m){
	return 1LL*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	n=read();
	init(n);
	ans=qpow(3,n);
	pw2[0]=1;
	for(int i=1;i<=n;++i){
		pw2[i]=(pw2[i-1]<<1)%mod;
	}
	for(int i=n/2+1;i<=n;++i){
		ans=(ans-2LL*C(n,i)*pw2[n-i]%mod+mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}

