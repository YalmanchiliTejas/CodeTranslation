#include<bits/stdc++.h>
#define N 3050
using namespace std;
int n,m;
int s[N][N],c[N][N];
inline int qpow(int d,int z,const int mod=m){
	int ret=1;
	for(;z;z>>=1,d=1ll*d*d%mod)
		if(z&1)ret=1l*ret*d%mod;
	return ret;
}
inline void init(int n,const int mod=m){
	s[0][0]=1;
	for(int i=0;i<=n;++i){c[i][0]=1;
		for(int j=1;j<=i;++j){
			s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j)%mod;
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
}
int main(){
	cin>>n>>m;init(n+1);
	int ans=0;
	const int mod=m;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=i;++j){
			if(i&1)ans+=mod-1ll*c[n][i]*s[i+1][j+1]%mod*qpow(2,qpow(2,n-i,mod-1))%mod*qpow(qpow(2,n-i),j)%mod;
			else ans+=1ll*c[n][i]*s[i+1][j+1]%mod*qpow(2,qpow(2,n-i,mod-1))%mod*qpow(qpow(2,n-i),j)%mod;
			if(ans>=mod)ans-=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}