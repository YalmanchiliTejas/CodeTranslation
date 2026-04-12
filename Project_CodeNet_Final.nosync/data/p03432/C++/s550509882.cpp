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
const int N=(1<<14)+5,M=205;
int r[N],rt[2][N<<1],lim,d,ilim;
void NTT(int *A,int ty){
    fp(i,0,lim-1)if(i<r[i])swap(A[i],A[r[i]]);
    for(R int mid=1;mid<lim;mid<<=1)
        for(R int j=0,t;j<lim;j+=(mid<<1))
            fp(k,0,mid-1)
                A[j+k+mid]=dec(A[j+k],t=mul(rt[ty][mid+k],A[j+k+mid])),
                A[j+k]=add(A[j+k],t);
    if(!ty)fp(i,0,lim-1)A[i]=mul(A[i],ilim);
}
int coef[N],fac[N],ifac[N],f[N],g[N],n,m,res;
inline int C(R int n,R int m){return m>n?0:1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;}
void init(int n=10000){
    fp(i,1,(1<<d)-1)r[i]=(r[i>>1]>>1)|((i&1)<<(d-1));
    for(R int t=(P-1)>>1,i=1,x,y;i<lim;i<<=1,t>>=1){
        x=ksm(3,t),y=ksm(332748118,t),rt[0][i]=rt[1][i]=1;
        fp(k,1,i-1)
            rt[1][i+k]=mul(rt[1][i+k-1],x),
            rt[0][i+k]=mul(rt[0][i+k-1],y);
    }
	fac[0]=ifac[0]=1;fp(i,1,n)fac[i]=mul(fac[i-1],i);
	ifac[n]=ksm(fac[n],P-2);fd(i,n-1,1)ifac[i]=mul(ifac[i+1],i+1);
	coef[0]=0;fp(i,1,lim>>1)coef[i]=ifac[i+2];
	NTT(coef,1);
}
void calc(){
	fp(i,0,n)g[i]=mul(f[i],ifac[i]);fp(i,n+1,lim-1)g[i]=0;
	NTT(g,1);
	fp(i,0,lim-1)g[i]=mul(g[i],coef[i]);
	NTT(g,0);
	fp(i,0,n)f[i]=add(mul(g[i],fac[i+2]),mul(f[i],(i*(i+1)>>1)+1));
//	puts("qwq");
//	fp(i,0,n)printf("%d ",f[i]);
//	puts("");
}
int main(){
//	freopen("testdata.in","r",stdin);
	scanf("%d%d",&n,&m);
	lim=1,d=0;while(lim<=(n<<1))lim<<=1,++d;
	ilim=ksm(lim,P-2);
	init();
	f[0]=1;
	fp(i,1,m)calc();
	fp(i,0,n)upd(res,mul(C(n,i),f[i]));
	printf("%d\n",res);
	return 0;
}