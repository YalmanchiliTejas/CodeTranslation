#include<bits/stdc++.h>
#define pb push_back
#define gc getchar 
using namespace std;
const int N=5e4+10,mod=998244353,g=3;
typedef long long ll;
typedef double db;
 
int n,m,ans,f[N],h[N],t[N],frc[N],nv[N],ivg;
 
char cp;
template<class T>inline void rd(T &x)
{
	cp=gc();x=0;int f=0;
	for(;!isdigit(cp);cp=gc()) if(cp=='-') f=1;
	for(;isdigit(cp);cp=gc()) x=x*10+(cp^48);
	if(f) x=-x;
}
 
inline int fp(int x,int y)
{
	int re=1;
	for(;y;y>>=1,x=(ll)x*x%mod)
	  if(y&1) re=(ll)re*x%mod;
	return re;
}
 
inline int ad(int x,int y){x+=y;return x>=mod?x-mod:x;}
inline int dc(int x,int y){x-=y;return x<0?x+mod:x;} 
inline int C(int n,int m)
{
	if(m>n) return 0;
	return (ll)frc[n]*nv[m]%mod*(ll)nv[n-m]%mod;
}
 
namespace poly{
   int rv[N],L,len;
   
   inline void ntt(int *e,int pr)
   {
   	   int i,j,k,ix,iy,pd,ori,G=pr?g:ivg;
   	   for(i=1;i<len;++i) if(i<rv[i]) swap(e[i],e[rv[i]]);
   	   for(i=1;i<len;i<<=1){
   	      ori=fp(G,(mod-1)/(i<<1));
   	      for(j=0;j<len;j+=(i<<1)){
   	      	for(pd=1,k=0;k<i;++k,pd=(ll)pd*ori%mod){
   	      		ix=e[j+k];iy=(ll)pd*e[j+i+k]%mod;
   	      		e[j+k]=ad(ix,iy);e[i+j+k]=dc(ix,iy);
			}
		  }
	   }
	   if(pr) return;
	   G=fp(len,mod-2);
	   for(i=0;i<len;++i) e[i]=(ll)e[i]*G%mod;
   }
   
   void mul(int *f,int *g,int n,int m)
   {
   	   int i;
   	   for(L=0,len=1;len<=n+m;len<<=1) L++;
	   for(i=1;i<len;++i) rv[i]=(rv[i>>1]>>1)|((i&1)<<(L-1));
	   for(i=n+1;i<len;++i) f[i]=0;
   	   for(i=m+1;i<len;++i) g[i]=0;
   	   ntt(f,1);ntt(g,1);
   	   for(i=0;i<len;++i) f[i]=(ll)f[i]*g[i]%mod;
	   ntt(f,0); 
   }
}
using namespace poly;
 
int main(){
	int i,j,x,y;ivg=fp(g,mod-2);
	rd(n);rd(m);
	f[0]=frc[0]=nv[0]=frc[1]=nv[1]=1;
    for(i=2;i<n+3;++i)
	  frc[i]=(ll)frc[i-1]*i%mod,
	  nv[i]=(ll)(mod-mod/i)*nv[mod%i]%mod;
	for(i=2;i<n+3;++i) nv[i]=(ll)nv[i-1]*nv[i]%mod;
	for(i=1;i<=n;++i) h[i]=nv[i+2];
	for(L=0,len=1;len<=(n<<1);len<<=1) L++;
	for(i=1;i<len;++i) rv[i]=((rv[i>>1]>>1)|((i&1)<<(L-1)));
	ntt(h,1);
	for(j=1;j<=m;++j){
		for(i=0;i<=n;++i) t[i]=(ll)nv[i]*f[i]%mod;
		for(i=n+1;i<len;++i) t[i]=0;
		ntt(t,1);
		for(i=0;i<len;++i) t[i]=(ll)h[i]*t[i]%mod;
		ntt(t,0);
		for(i=0;i<=n;++i)
		 f[i]=ad((ll)(1+C(i+1,2))*f[i]%mod,(ll)t[i]*frc[i+2]%mod);
	}
	for(i=0;i<=n;++i) ans=ad(ans,(ll)C(n,i)*f[i]%mod);
	printf("%d",ans);
	return 0;
}