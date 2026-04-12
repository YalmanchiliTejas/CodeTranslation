#include<bits/stdc++.h>
using namespace std;
#define cs const
#define re register
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define fi first
#define se second
#define bg begin
cs int RLEN=1<<20|1;
inline char gc(){
    static char ibuf[RLEN],*ib,*ob;
    (ib==ob)&&(ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
    return (ib==ob)?EOF:*ib++;
}
inline int read(){
    char ch=gc();
    int res=0;bool f=1;
    while(!isdigit(ch))f^=ch=='-',ch=gc();
    while(isdigit(ch))res=(res+(res<<2)<<1)+(ch^48),ch=gc();
    return f?res:-res;
}
template<typename tp>inline void chemx(tp &a,tp b){a<b?a=b:0;}
template<typename tp>inline void chemn(tp &a,tp b){a>b?a=b:0;}
cs int mod=998244353,G=3;
inline int add(int a,int b){return (a+=b)>=mod?(a-mod):a;}
inline int dec(int a,int b){a-=b;return a+(a>>31&mod);}
inline int mul(int a,int b){static ll r;r=1ll*a*b;return (r>=mod)?(r%mod):r;}
inline void Add(int &a,int b){(a+=b)>=mod?(a-=mod):0;}
inline void Dec(int &a,int b){a-=b,a+=a>>31&mod;}
inline void Mul(int &a,int b){static ll r;r=1ll*a*b;a=(r>=mod)?(r%mod):r;}
inline int ksm(int a,int b,int res=1){for(;b;b>>=1,Mul(a,a))(b&1)&&(Mul(res,a),1);return res;}
inline int Inv(int x){return ksm(x,mod-2);}
cs int N=32005;
int rev[N];
inline void init_rev(int lim){
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));
}
inline void ntt(int *f,int lim,int kd){
	for(int i=0;i<lim;i++)if(i>rev[i])swap(f[i],f[rev[i]]);
	for(int a0,a1,mid=1;mid<lim;mid<<=1){
		int wn=ksm(G,(mod-1)/(mid<<1));
		for(int i=0;i<lim;i+=mid<<1)
		for(int j=0,w=1;j<mid;j++,Mul(w,wn))
		a0=f[i+j],a1=mul(f[i+j+mid],w),f[i+j]=add(a0,a1),f[i+j+mid]=dec(a0,a1);
	}
	if(kd==-1){
		reverse(f+1,f+lim);
		for(int i=0,iv=Inv(lim);i<lim;i++)Mul(f[i],iv);
	}
}
int fac[N],ifac[N];
inline void init_inv(cs int len=N-5){
	fac[0]=ifac[0]=1;
	for(int i=1;i<=len;i++)fac[i]=mul(fac[i-1],i);
	ifac[len]=Inv(fac[len]);
	for(int i=len-1;i;i--)ifac[i]=mul(ifac[i+1],i+1);
}
inline int C(int n,int m){return n<m?0:mul(fac[n],mul(ifac[m],ifac[n-m]));}
int lim,n,m,f[N],a[N],g[N];
int main(){
	#ifdef Stargazer
	freopen("lx.in","r",stdin);
	#endif
	n=read(),m=read();
	lim=1;init_inv();
	while(lim<=n*2)lim<<=1;
	init_rev(lim);
	for(int i=1;i<=n;i++)g[i]=ifac[i+2];
	ntt(g,lim,1);
	a[0]=1;
	for(int i=1;i<=m;i++){
		for(int j=0;j<=n;j++)f[j]=mul(a[j],ifac[j]);
		ntt(f,lim,1);
		for(int j=0;j<lim;j++)Mul(f[j],g[j]);
		ntt(f,lim,-1);
		for(int j=0;j<=n;j++)a[j]=add(mul(f[j],fac[j+2]),mul(a[j],(1+j+C(j,2))%mod));
		for(int j=0;j<lim;j++)f[j]=0;
	}
	int ret=0;
	for(int i=0;i<=n;i++)Add(ret,mul(C(n,i),a[i]));
	cout<<ret<<'\n';
}
