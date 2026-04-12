#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define db double
#define pint pair<int,int>
#define mk(x,y) make_pair(x,y)
#define fir first
#define sec second
#define Rep(x,y,z) for(int x=y;x<=z;x++)
#define Red(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
const int MAXN=1e7+5,Mod=998244353;
char buf[1<<12],*pp1=buf,*pp2=buf,nc;int ny;
inline char gc() {return pp1==pp2&&(pp2=(pp1=buf)+fread(buf,1,1<<12,stdin),pp1==pp2)?EOF:*pp1++;}
//inline char gc(){return getchar();}
inline int read(){
	int x=0;for(ny=1;nc=gc(),(nc<48||nc>57)&&nc!=EOF;)if(nc==45)ny=-1;if(nc<0)return nc;
	for(x=nc-48;nc=gc(),47<nc&&nc<58&&nc!=EOF;x=(x<<3)+(x<<1)+(nc^48));return x*ny;
}
int n,Fac[MAXN],iFac[MAXN],Fpow[MAXN];
inline int Fp(int x,int k){int ans=1;for(;k;k>>=1,x=1ll*x*x%Mod)if(k&1)ans=1ll*ans*x%Mod;return ans;}
inline int C(int n,int m){return n<0||m<0||n<m?0:1ll*Fac[n]*iFac[m]%Mod*iFac[n-m]%Mod;}
int main(){
//	freopen("std.in","r",stdin);
//	freopen("std.out","w",stdout);
	n=read();
	Fac[0]=Fpow[0]=1;Rep(i,1,n)Fac[i]=1ll*Fac[i-1]*i%Mod,Fpow[i]=(Fpow[i-1]<<1)%Mod;
	iFac[n]=Fp(Fac[n],Mod-2);Red(i,n,1)iFac[i-1]=1ll*iFac[i]*i%Mod;
	int ans=0;Rep(i,n/2+1,n)ans=(ans+1ll*C(n,i)*Fpow[n-i])%Mod;ans=ans*2%Mod;
	ans=(Fp(3,n)-ans+Mod)%Mod,cout<<ans<<'\n';
	return 0;
}


