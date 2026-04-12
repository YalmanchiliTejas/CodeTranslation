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
inline int inc(R int x,R int y){return x+y>=P?x+y-P:x+y;}
inline int dec(R int x,R int y){return x-y<0?x-y+P:x-y;}
inline int mul(R int x,R int y){return 1ll*x*y-1ll*x*y/P*P;}
int ksm(R int x,R int y){
	R int res=1;
	for(;y;y>>=1,x=mul(x,x))(y&1)?res=mul(res,x):0;
	return res;
}
const int N=1e7+5;
int fac[N],ifac[N],bin[N],n,res;
inline int C(R int n,R int m){return m>n?0:1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;}
int main(){
	scanf("%d",&n);
	fac[0]=ifac[0]=1;fp(i,1,n)fac[i]=mul(fac[i-1],i);
	ifac[n]=ksm(fac[n],P-2);fd(i,n-1,1)ifac[i]=mul(ifac[i+1],i+1);
	bin[0]=1;fp(i,1,n+1)bin[i]=mul(bin[i-1],2);
	res=ksm(3,n);
	fp(i,(n>>1)+1,n)upd(res,P-mul(C(n,i),bin[n-i+1]));
	printf("%d\n",res);
	return 0;
}