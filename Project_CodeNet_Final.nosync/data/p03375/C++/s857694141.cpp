#include<bits/stdc++.h>
#define ll long long
#define cri const register int
#define re register
using namespace std;
int C[3002][3002],S[3002][3002];
inline int read(){
	int x;scanf("%d",&x);
	return x;
}
inline int mo(cri x,cri y){
	return x>=y?x-y:x;
}
inline int qpow(int a,int b,cri mod,int ans=1){
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	cri n=read(),mod=read();
	for(int i=0;i<=n;i++)
		for(int j=C[i][0]=1;j<=i;j++) C[i][j]=mo(C[i-1][j]+C[i-1][j-1],mod);
	for(int i=S[0][0]=1;i<=n+1;i++)
		for(int j=1;j<=i;j++) S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*j)%mod;
	int pw=qpow(2,n,mod),ans=0;
	for(int i=0;i<=n;i++){
		int tmp=0;
		for(int j=0,Pw=1;j<=i;j++,Pw=1ll*Pw*pw%mod)
			tmp=(tmp+1ll*S[i+1][j+1]*Pw)%mod;
		ans=(ans+(i&1?mod-1ll:1ll)*C[n][i]%mod*qpow(2,qpow(2,n-i,mod-1),mod)%mod*tmp)%mod;
		pw=1ll*pw*(mod+1>>1)%mod;
	}
	cout<<ans<<endl;
}