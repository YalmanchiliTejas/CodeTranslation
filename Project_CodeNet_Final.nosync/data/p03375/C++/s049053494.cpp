#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,mod,i,j,k,f[3005][3005],c[3005][3005],pw[3005],ans;
void inc(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
void dec(int &x,int y){
	x-=y;if(x<0)x+=mod;
}
int main(){
	cin>>n>>mod;
	f[0][0]=c[0][0]=1;
	rep(i,n){
		c[i][0]=f[i][0]=1;
		rep(j,i){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
			f[i][j]=(f[i-1][j-1]+1ll*(j+1)*f[i-1][j])%mod;
		}
	}
	int cpw=2;
	for(i=0;i<=n;i++) pw[i]=1;
	for(k=n;k>=0;k--){
		int sum=0;
		for(i=0;i<=k;i++){
			sum=(sum+1ll*f[k][i]*pw[i])%mod;
		}
		int tmp=1ll*c[n][k]*cpw%mod*sum%mod;
		if(k&1) dec(ans,tmp); else inc(ans,tmp);
		int p2=1;
		for(i=0;i<=n;i++){
			pw[i]=1ll*pw[i]*p2%mod;
			p2=2ll*p2%mod;
		}
		cpw=1ll*cpw*cpw%mod;
	}
	cout<<ans<<endl;
	return 0;
}