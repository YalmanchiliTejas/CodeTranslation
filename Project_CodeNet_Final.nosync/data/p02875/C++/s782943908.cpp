//by Judge
#define HGS_AK_IOI true
#include<cstdio>
#include<cstring>
#include<iostream>
#define Rg register
#define fp(i,a,b) for(Rg int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(Rg int i=(a),I=(b)-1;i>I;--i)
#define ll long long
using namespace std;
const int mod=998244353;
const int M=1e7+3;
typedef int arr[M];
char buf[1<<21],*p1=buf,*p2=buf;
int n,ans; arr pw2,fac,inv;
inline int mul(int x,int y){return 1ll*x*y%mod;}
inline void Pls(int& x,int y){if((x+=y)>=mod)x-=mod;}
inline int qpow(int x,int p=mod-2){ Rg int s=1;
	for(;p;p>>=1,x=mul(x,x)) if(p&1) s=mul(s,x); return s;
}
inline int C(int n,int m){ return mul(fac[n],mul(inv[m],inv[n-m])); }
int main(){ cin>>n,pw2[0]=fac[0]=1,ans=qpow(3,n);
	fp(i,1,n) pw2[i]=mul(pw2[i-1],2),fac[i]=mul(fac[i-1],i);
	inv[n]=qpow(fac[n]); fd(i,n,1) inv[i-1]=mul(inv[i],i);
	fp(i,0,(n-1)>>1) Pls(ans,mod-mul(pw2[i+1],C(n,n-i))); return !printf("%d\n",ans);
}