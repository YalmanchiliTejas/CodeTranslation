#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3005;
LL n,mo,fac[N],inv[N],c[N][N],g[N][N];
LL qpow(LL x,LL k,LL p)
{
	LL ret=1;
	while(k){
		if(k&1) ret*=x,ret%=p;
		x*=x,x%=p;k>>=1;
	}
	return ret;
}
int main()
{
	cin>>n>>mo;
	fac[0]=1;
	for(int i=1;i<=n+1;i++) fac[i]=(fac[i-1]*i)%mo;
	inv[n+1]=qpow(fac[n+1],mo-2,mo);
	for(int i=n;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%mo;
	c[0][0]=1;
	for(int i=1;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		  c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
	}
	for(int i=0;i<=n;i++){
		g[i][0]=1;
		for(int j=1;j<=i;j++){
			g[i][j]=(g[i-1][j-1]+g[i-1][j]*(j+1))%mo;
		}
	}
	LL ans=0;
	for(int i=0;i<=n;i++){
		LL x=0,f=0,k=1,y=0;
		x=qpow(2,qpow(2,n-i,mo-1),mo);
		y=qpow(2,n-i,mo);
		for(int j=0;j<=i;j++){
			f=(f+(g[i][j]*k)%mo)%mo;
//			cout<<f<<' ';
			(k*=y)%=mo;
		}
		LL ret=c[n][i]*x%mo*f%mo;
//		cout<<i<<' '<<ret<<' '<<f<<' '<<x<<' '<<c[n][i]<<endl;
		if(i&1) ans=(ans-ret+mo)%mo;
		else ans=(ans+ret)%mo;
	}
	cout<<ans<<endl;
	return 0;
}
