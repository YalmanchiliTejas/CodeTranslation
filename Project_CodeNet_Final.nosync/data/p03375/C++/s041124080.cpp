#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x); i<=(y); i++)
#define per(i,x,y) for (int i=(x); i>=(y); i--)
#define ll long long
#define ld long double
#define inf 1000000000
using namespace std;
#define N 3005
int n,mod,f[N],s[N][N],pw[N*N],fac[N],inv[N],ans;
int ksm(int x,int p,int mod){
	int ret=1;
	for (x%=mod; p; p>>=1,x=(ll)x*x%mod) if (p&1) ret=(ll)ret*x%mod;
	return ret;
}
int getinv(int x){ return ksm(x,mod-2,mod); }
int C(int n,int m){ return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod; }
void pre(int n){
	pw[0]=1; rep (i,1,n*n) pw[i]=2ll*pw[i-1]%mod;
	fac[0]=1; rep (i,1,n) fac[i]=(ll)fac[i-1]*i%mod;
	inv[n]=getinv(fac[n]); per (i,n-1,0) inv[i]=(ll)inv[i+1]*(i+1)%mod;
}
int main(){
	scanf("%d%d",&n,&mod); pre(n);
	rep (i,0,n) s[i][0]=1;
	rep (i,1,n) rep (j,1,i) s[i][j]=(s[i-1][j-1]+(ll)(j+1)*s[i-1][j]%mod)%mod;
	rep (i,0,n){
		rep (j,0,i) f[i]=(f[i]+(ll)s[i][j]*pw[(n-i)*j]%mod)%mod;
		f[i]=(ll)f[i]*ksm(2,ksm(2,n-i,mod-1),mod)%mod;
	}
	rep (i,0,n) ans=(ans+mod+((i&1)?-1ll:1ll)*f[i]*C(n,i)%mod)%mod;
	cout<<ans<<endl;
	return 0;
}