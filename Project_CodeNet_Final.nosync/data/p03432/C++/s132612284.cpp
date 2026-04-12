#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<14,p=998244353,R=3;
int read(){
	int f=1,g=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) g=g*10+ch-'0';
	return f*g;
}
int qpow(int x,int k){
	int t=1;
	for (;k;k>>=1){
		if (k&1) t=(ll)t*x%p;
		x=(ll)x*x%p;
	}
	return t;
}
int n,m,L,ans,f[N],a[N],g[N],fac[N],inv[N];
int C(int n,int m){return (ll)fac[n]*inv[m]%p*inv[n-m]%p;}
int pl(int x,int y){return (x+y<p) ? (x+y) : (x+y-p);}
void NTT(int *a,int L,int typ){
	for (int i=0,j=0;i<L;i++){
		if (i<j) swap(a[i],a[j]);
		for (int k=L>>1;(j^=k)<k;k>>=1);
	}
	for (int k=1;k<L;k<<=1){
		int wn=qpow(R,(p-1)/(k<<1));
		if (typ==0) wn=qpow(wn,p-2);
		for (int i=0;i<L;i+=(k<<1)){
			int w=1;
			for (int j=i;j<i+k;j++,w=(ll)w*wn%p){
				int x=a[j],y=(ll)a[j+k]*w%p;
				a[j]=pl(x,y);a[j+k]=pl(x,p-y);
			}
		}
	}
	if (typ==0){
		int inv=qpow(L,p-2);
		for (int i=0;i<L;i++) a[i]=(ll)a[i]*inv%p;
	}
}
int main(){
	n=read();m=read();
	fac[0]=1;
	for (int i=1;i<=n+2;i++) fac[i]=(ll)fac[i-1]*i%p;
	inv[n+2]=qpow(fac[n+2],p-2);
	for (int i=n+2;i;i--) inv[i-1]=(ll)inv[i]*i%p;
	f[0]=1;int L=1;
	while (L<=n+n) L<<=1;
	for (int i=1;i<=n;i++) g[i]=inv[i+2];
	NTT(g,L,1);
	for (int i=1;i<=m;i++){
		for (int i=0;i<L;i++) a[i]=(i<=n) ? ((ll)f[i]*inv[i]%p) : 0;
		NTT(a,L,1);
		for (int i=0;i<L;i++) a[i]=(ll)a[i]*g[i]%p;
		NTT(a,L,0);
		for (int i=0;i<=n;i++) f[i]=((ll)f[i]*(i*(i+1)/2+1)+(ll)a[i]*fac[i+2])%p;
	}
	ans=0;
	for (int i=0;i<=n;i++) ans=(ans+(ll)C(n,i)*f[i])%p;
	printf("%d\n",ans);
	return 0;
}