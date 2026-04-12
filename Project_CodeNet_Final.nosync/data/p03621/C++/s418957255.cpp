//minamoto
#include<bits/stdc++.h>
#define R register
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
const int P=998244353;
inline void upd(R int &x,R int y){(x+=y)>=P?x-=P:0;}
inline int add(R int x,R int y){return x+y>=P?x+y-P:x+y;}
inline int dec(R int x,R int y){return x-y<0?x-y+P:x-y;}
inline int mul(R int x,R int y){return 1ll*x*y-1ll*x*y/P*P;}
int ksm(R int x,R int y){
	R int res=1;
	for(;y;y>>=1,x=mul(x,x))(y&1)?res=mul(res,x):0;
	return res;
}
const int N=10005;
char s[N],t[N];int fac[N],ifac[N],f[N][N],n,cnta,cntb;
inline int C(R int n,R int m){return m>n?0:1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;}
inline void init(int n=10000){
	fac[0]=ifac[0]=1;fp(i,1,n)fac[i]=mul(fac[i-1],i);
	ifac[n]=ksm(fac[n],P-2);fd(i,n-1,1)ifac[i]=mul(ifac[i+1],i+1);
}
int main(){
	init();
	scanf("%s%s",s+1,t+1),n=strlen(s+1);
	fp(i,1,n){
		cnta+=(s[i]=='1'&&t[i]=='1');
		cntb+=(s[i]=='1'&&t[i]=='0');
	}
	f[0][0]=1;
	fp(j,1,cntb)f[0][j]=mul(fac[j],fac[j]);
	fp(i,1,cnta)fp(j,1,cntb)
		f[i][j]=(1ll*i*j%P*f[i-1][j]+1ll*j*j%P*f[i][j-1])%P;
	R int res=0;
	fp(i,0,cnta){
		R int j=cnta-i;
		upd(res,1ll*f[i][cntb]*fac[j]%P*fac[j]%P*C(cnta,j)%P*C(cnta+cntb,j)%P);
	}
	printf("%d\n",res);
	return 0;
}