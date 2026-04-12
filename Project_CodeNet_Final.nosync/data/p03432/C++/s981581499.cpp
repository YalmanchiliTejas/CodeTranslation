#include<bits/stdc++.h>
using namespace std;
const int N=8005,M=205,mod=998244353,G=3,Gi=(mod+1)/3;
inline int read(){
    int s=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
    return s*f;
}
inline int pls(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int dec(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=mul(a,a)) if(b&1) res=mul(res,a);
	return res;
}
int n,m,bit=2,rev[N<<2];
int a[N<<2],b[N<<2];
int inv[N],fac[N],f[N];

inline void init(){
	fac[0]=1;
	for(int i=1;i<=n+2;i++) fac[i]=mul(fac[i-1],i);
	inv[n+2]=qpow(fac[n+2],mod-2);
	for(int i=n+1;i>=0;i--) inv[i]=mul(inv[i+1],i+1);
}
inline int C(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return mul(fac[n],mul(inv[m],inv[n-m]));
}
inline void get_rev(){
	for(int i=0;i<bit;i++) rev[i]=(rev[i>>1]>>1)|(bit>>1)*(i&1);
}
inline void ntt(int *a,int dft){
	for(int i=0;i<bit;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=1;i<bit;i<<=1){
		int W=qpow(dft==1?G:Gi,(mod-1)/(i<<1));
		for(int j=0;j<bit;j+=(i<<1))
			for(int k=j,w=1;k<i+j;k++,w=mul(w,W)){
				int x=a[k],y=mul(w,a[k+i]);
				a[k]=pls(x,y),a[k+i]=dec(x,y);
			}
	}
	if(dft==-1) for(int i=0,inv=qpow(bit,mod-2);i<bit;i++) a[i]=mul(a[i],inv);
}
int main(){
	scanf("%d%d",&n,&m);
	init();
	while(bit<=2*n) bit<<=1;
	get_rev();
	for(int i=1;i<=n;i++) b[i]=inv[i+2];
	ntt(b,1);
	f[0]=1;a[0]=1;
	for(int i=1;i<=m;i++){
		ntt(a,1);
		for(int j=0;j<bit;j++) a[j]=mul(a[j],b[j]);
		ntt(a,-1);
		for(int j=0;j<=n;j++) {
			f[j]=pls(mul(a[j],fac[j+2]),mul(f[j],1+j+C(j,2)));
			a[j]=mul(f[j],inv[j]);
		}
		for(int j=n+1;j<bit;j++) a[j]=0;
	}
	int ans=0;
	for(int i=0;i<=n;i++) ans=pls(ans,mul(C(n,i),f[i]));
	printf("%d",ans);
	return 0;
}